#include <minisat/utils/StatsCollector.h>

using namespace Minisat;

void StatsCollector::newLearnt(unsigned int ls) {
    if (ls > _max_learnt) {
        _max_learnt = ls;
    }
    _mean_learnt += ls;
    _learntSize.push_back(ls);
}
void StatsCollector::newWatches(unsigned int ws) {
    if (ws > _max_watches) {
        _max_watches = ws;
    }
    _mean_watches += ws;
    _watchesSize.push_back(ws);
}

void StatsCollector::outputLearnt(const char* filename) {
    std::ofstream fd(filename, std::ofstream::out);
    for(unsigned int val : _learntSize) {
        fd << val << std::endl;
    }
    fd.close();
}

void StatsCollector::outputWatches(const char* filename) {
    std::ofstream fd(filename, std::ofstream::out);
    for(unsigned int val : _watchesSize) {
        fd << val << std::endl;
    }
    fd.close();
}

void StatsCollector::outputCSV(const char* filename) {
    std::ofstream fd(filename, std::ofstream::out);
    fd << "Learnt,Watches,Assignment" << std::endl;
    for(unsigned int i = 0; i < _learntSize.size(); i++) {
        fd << _learntSize[i] << "," << _watchesSize[i]  << std::endl;
    }
    fd.close();
}

void StatsCollector::syntheticOutput() {
    _compute_means();
    fprintf(stderr, "+=============================+\n");
    fprintf(stderr, "|         Statisticts         |\n");
    fprintf(stderr, "|-----------------------------|\n");
    fprintf(stderr, "| Problem size: %13d |\n", _problemSize);
    fprintf(stderr, "|-----------------------------|\n");
    fprintf(stderr, "| Max learnt: %15d |\n", _max_learnt);
    fprintf(stderr, "| Mean learnt: %14d |\n", _mean_learnt);
    fprintf(stderr, "|-----------------------------|\n");
    fprintf(stderr, "| Max Watches: %14d |\n", _max_watches);
    fprintf(stderr, "| Mean Watches: %13d |\n", _mean_watches);
    fprintf(stderr, "+=============================+\n");
}

#include <minisat/utils/StatsCollector.h>

using namespace Minisat;

void StatsCollector::newLearnt(long unsigned int ls) {
    long double old_mean = _mean_learnt;
    if (ls > _max_learnt) {
        _max_learnt = ls;
    }
    _learntSize.push_back(ls);
    _mean_learnt += ((ls - _mean_learnt) / _learntSize.size());
    _variance_learnt += (ls - old_mean)*(ls - _mean_learnt);
    _stdev_learnt = sqrt(_variance_learnt / _learntSize.size());
}
void StatsCollector::newWatches(long unsigned int ws) {
    long double old_mean = _mean_watches;
    if (ws > _max_watches) {
        _max_watches = ws;
    }
    _watchesSize.push_back(ws);
    _mean_watches += ((ws - _mean_watches) / _watchesSize.size());
    _variance_watches += (ws - old_mean)*(ws - _mean_watches);
    _stdev_watches = sqrt(_variance_watches / _watchesSize.size());
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
    fd << "Learnt,Watches" << std::endl;
    for(unsigned int i = 0; i < _learntSize.size(); i++) {
        fd << _learntSize[i] << "," << _watchesSize[i]  << std::endl;
    }
    fd.close();
}

void StatsCollector::syntheticOutput(const char* filename="stderr") {
    FILE* file;
    if (strcmp(filename, "stderr") == 0) {
        file = stderr;
    } else {
        file = fopen(filename, "w");
    }
    fprintf(file, "+=============================+\n");
    fprintf(file, "|         Statisticts         |\n");
    fprintf(file, "|-----------------------------|\n");
    fprintf(file, "| Problem size: %11lu B |\n", _problemSize);
    fprintf(file, "|-----------------------------|\n");
    fprintf(file, "| Max learnt: %13lu B |\n", _max_learnt);
    fprintf(file, "| Mean learnt: %12.0Lf B |\n", _mean_learnt);
    fprintf(file, "| Std dev learnt: %9.0Lf B |\n", _stdev_learnt);
    fprintf(file, "|-----------------------------|\n");
    fprintf(file, "| Max Watches: %12lu B |\n", _max_watches);
    fprintf(file, "| Mean Watches: %11.0Lf B |\n", _mean_watches);
    fprintf(file, "| Std dev Watches: %8.0Lf B |\n", _stdev_watches);
    fprintf(file, "+=============================+\n");
}

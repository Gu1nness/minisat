#ifndef Minisat_StatsCollector_h
#define Minisat_StatsCollector_h

#include <vector>
#include <iostream>
#include <cstdio>
#include <fstream>

namespace Minisat {

    class StatsCollector {
        unsigned int _problemSize;
        std::vector<unsigned int> _learntSize;
        std::vector<unsigned int> _watchesSize;

        unsigned int _max_learnt = 0;
        unsigned int _max_watches = 0;

        double _mean_learnt = 0;
        double _mean_watches = 0;

        public:
            explicit StatsCollector() : _problemSize(0) {}
            virtual ~StatsCollector() {}

            // Push data in the structure
            void set_problemSize(unsigned int ps) { _problemSize = ps; }
            void newLearnt(unsigned int ls);
            void newWatches(unsigned int ws);

            // Print data.
            void outputLearnt(const char* filename);
            void outputWatches(const char* filename);
            void outputCSV(const char* filename);
            void syntheticOutput();
    };
} // namespace Minisat

#endif // Minisat_StatsCollector_h

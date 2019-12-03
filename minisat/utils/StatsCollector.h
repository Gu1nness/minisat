#ifndef Minisat_StatsCollector_h
#define Minisat_StatsCollector_h

#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <fstream>

namespace Minisat {

    class StatsCollector {
        long unsigned int _problemSize;
        std::vector<long unsigned int> _learntSize;
        std::vector<long unsigned int> _watchesSize;

        long unsigned int _max_learnt = 0;
        long unsigned int _max_watches = 0;

        long double _mean_learnt = 0;
        long double _mean_watches = 0;

        long double _variance_learnt = 0;
        long double _variance_watches = 0;

        long double _stdev_learnt = 0;
        long double _stdev_watches = 0;

        public:
            explicit StatsCollector() : _problemSize(0) {}
            virtual ~StatsCollector() {}

            // Push data in the structure
            void set_problemSize(long unsigned int ps) { _problemSize = ps; }
            void newLearnt(long unsigned int ls);
            void newWatches(long unsigned int ws);

            // Print data.
            void outputLearnt(const char* filename);
            void outputWatches(const char* filename);
            void outputCSV(const char* filename);
            void syntheticOutput(const char*);
    };
} // namespace Minisat

#endif // Minisat_StatsCollector_h

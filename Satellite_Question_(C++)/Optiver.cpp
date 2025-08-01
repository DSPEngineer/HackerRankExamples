#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using SatelliteId = int64_t;


void OnSatelliteReportBack( SatelliteId  satelliteId )
{
    // Don’t change this code
    std::cout << "SatelliteReportedBack: " << satelliteId << std::endl;
}


void ErrDuplicateSatellite(SatelliteId satelliteId)
{
      // Don't change this code
      std::cout << "E1: " << satelliteId << std::endl;
}

void ErrInvalidSatellite(SatelliteId satelliteId)
{
       // Don't change this code
      std::cout << "E2: " << satelliteId << std::endl;
}


class SatelliteNetwork{
    public:
        void SatelliteConnected(SatelliteId satelliteId)
        {
              // Your code here…
            satellitesConnected.push_back(satelliteId);
        }

        void RelationshipEstablished(SatelliteId satelliteId1, SatelliteId satelliteId2)
        {
              // Your code here…
        }

        void MessageReceived(const std::vector<SatelliteId>& notifiedSatellites )
        {
              // Your code here…
        }

private:
    const std::string connected = "SatelliteConnected";
    const std::string established = "RelationshipEstablished";
    const std::string messageReceived = "MessageReceived";

    std::vector<SatelliteId> satellitesConnected;

};

int main()
{
     int64_t N = 0u;
     std::cin >> N;

     SatelliteNetwork network;
     for( size_t  i = 0; i < N; ++i )
     {
         std::string instructionText;
         std::cin >> instructionText;

         if( instructionText == "SatelliteConnected" )
         {
              SatelliteId  satelliteId = 0;
              std::cin >> satelliteId;
              network.SatelliteConnected(  satelliteId );
         }
         else if( instructionText == "RelationshipEstablished" )
         {
              SatelliteId  fromSatelliteId = 0, toSatelliteId = 0;
              std::cin >> fromSatelliteId >> toSatelliteId ;
              network.RelationshipEstablished( fromSatelliteId, toSatelliteId );
         }
         else if( instructionText == "MessageReceived" )
         {
               uint64_t  M = 0u;
               std::cin >>  M;
               std::vector<SatelliteId>  notifiedSatellites;

               for( int j = 0; j < M;  ++j )
               {
                     SatelliteId notifiedSatellite;
                     std::cin >> notifiedSatellite;
                     notifiedSatellites.push_back( notifiedSatellite );
               }

              network.MessageReceived( notifiedSatellites );
         }
         else
         {
               std::cerr << "Malformed input! " << instructionText << std::endl;
//               std::cout << "Malformed input! " << instructionText << std::endl;
               return -1;
          }
      }

 return 0;
}

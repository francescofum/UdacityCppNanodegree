#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <cstddef>

class Model
{
public:
    // Contains the X and Y coordinated of the Node.
    struct Node {
        double x = 0.f;
        double y = 0.f;
    };
    // Contains a list of nodes forming a way.
    struct Way {
        std::vector<int> nodes;
    };
    // Types of road. We DONT want footway (and probably others).
    struct Road {
        enum Type { Invalid, Unclassified, Service, Residential,
            Tertiary, Secondary, Primary, Trunk, Motorway, Footway };
        int way;
        Type type;
    };
    // lol
    struct Railway {
        int way;
    };    
    // like a river?
    struct Multipolygon {
        std::vector<int> outer;
        std::vector<int> inner;
    };
    
    struct Building : Multipolygon {};
    
    struct Leisure : Multipolygon {};
    
    struct Water : Multipolygon {};
    
    struct Landuse : Multipolygon {
        enum Type { Invalid, Commercial, Construction, Grass, Forest, Industrial, Railway, Residential };
        Type type;
    };
    // Constructor for the model class. 
    // @param &xml : reference to an xml (path?).
    Model( const std::vector<std::byte> &xml );
    // Getter for the metric scale. 
    auto MetricScale() const noexcept { return m_MetricScale; }    
    //???
    auto &Nodes() const noexcept { return m_Nodes; }
    auto &Ways() const noexcept { return m_Ways; }
    auto &Roads() const noexcept { return m_Roads; }
    auto &Buildings() const noexcept { return m_Buildings; }
    auto &Leisures() const noexcept { return m_Leisures; }
    auto &Waters() const noexcept { return m_Waters; }
    auto &Landuses() const noexcept { return m_Landuses; }
    auto &Railways() const noexcept { return m_Railways; }
    
private:
    // Private function Adjust coordinates. 
    void AdjustCoordinates();
    // Private function to draw start and stop points?
    // @param &mp : a multipolygon
    void BuildRings( Multipolygon &mp );
    // Private function to load the data. 
    // @param &xml : path to xml file. 
    void LoadData(const std::vector<std::byte> &xml);
    
    // Private variables.
    // A list of type Node called m_Nodes.
    std::vector<Node> m_Nodes;
    // A list of type Wat called m_Ways
    std::vector<Way> m_Ways;
      // A list of type Wat called m_Roads  
    std::vector<Road> m_Roads;
    // A list of type Wat called m_Railways
    std::vector<Railway> m_Railways;
    // A list of type Wat called m_Buildings
    std::vector<Building> m_Buildings;
    // A list of type Wat called m_Leisures
    std::vector<Leisure> m_Leisures;
    // A list of type Wat called m_Waters
    std::vector<Water> m_Waters;
    // A list of type Wat called m_Landuses
    std::vector<Landuse> m_Landuses;
    
    double m_MinLat = 0.;
    double m_MaxLat = 0.;
    double m_MinLon = 0.;
    double m_MaxLon = 0.;
    double m_MetricScale = 1.f;
};

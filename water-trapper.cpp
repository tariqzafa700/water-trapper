#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_water(vector<int>& heights)
{
    auto max = max_element(heights.begin(), heights.end());
    cout << *max << endl;
    vector<vector<int>> levels(*max, vector<int>(heights.size(), 0));

    for(auto i = 0; i < heights.size(); ++i)
    {
        if(heights[i] > 0)
        {
            for(auto j = *max - heights[i]; j < *max; ++j )
            {
                levels[j][i] = 1;
            }
        }
    }
    cout << "reassigned" << endl;
    for(auto& i:levels)
    {
        for(auto& j:i)
        {
             cout << j << " ";
        }
        cout << endl;
    }

}

int main(int, char**)
{
    //vector<int> hts = {0, 1, 2, 1, 2, 1, 0};
    vector<int> hts = {0,1,0,2,1,0,1,3,2,1,2,1};
    find_water(hts);
}

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
int main()
{
    if(system("g++ data.cpp -o data -std=c++14 -O2")||system("g++ force.cpp -o force -std=c++14 -O2")||system("g++ migrate.cpp -o migrate -std=c++14 -O2"))
        return 0;
    int tot=0;
    while(++tot)
    {
        cout<<tot<<'\n';
        if(system("./data")||system("./force")||system("./migrate")||system("diff migrate.out migrate.ans -B -Z -s"))
            return 0;
    }
    return 0;
}
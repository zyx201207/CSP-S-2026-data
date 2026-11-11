#include <bits/stdc++.h>
using namespace std;


struct subway{
    int s;
    int t;
};
int c,n,m,d,q;
int num,order,tim;
vector<int> station;
vector<subway> sub[501];
int mm[501][501];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        station.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>order>>tim;
            sub[j].push_back({order,tim});
        }
    }
    return 0;
}

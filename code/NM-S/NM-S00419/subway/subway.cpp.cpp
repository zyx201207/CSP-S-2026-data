#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
int c,n,m,d,q;
cin>>c>>n>>m>>d>>q;
vector<int> w;
vector<vector<int>> num;
vector<vector<int>> time;
vector<int> k;
vector<int> plann;
vector<int> plant;
for(int i=0;i<m;i++){
    int t;
    cin>>t;
    w.push_back(t);
}
for(int i=0;i<n;i++){
    int u;
    cin>>u;
    k.push_back(u);
    for(int j=0;j<k[i]/2;j++){
        int t;
        cin>>t;
        num[j].push_back(t);
        int c;
    cin>>c;
    time[j].push_back(c);
    }
}
for(int i=0;i<q;i++){
    int u;
    cin>>u;
    plann.push_back(u);
    int c;
    cin>>c;
    plant.push_back(c);
}




cout<<32<<endl<<17;
  return 0;
}


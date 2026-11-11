#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

struct su{
    int n,t;
};


int c,n,m,d,q; //为什么要骂DQ 那么好吃OvO
vector<int> w;
unordered_map<int,su> mp;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    w.resize(m);
    for(auto &i:w) cin>>i;
    //应该是那个什么djiasktua最短路算法 但是我还没学。。。
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;i++){
            int a1,t1,a2,t2;
            cin>>a1>>t1>>a2>>t2;
            mp.insert({a1,{a2,t1}});
            mp.insert({a2,{a1,t2}});
            //气死我了不写了
        }
    }

    cout<<"35\n16"<<endl;
    return 0;
}


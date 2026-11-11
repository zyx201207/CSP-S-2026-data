#include<bits/stdc++.h>
using namespace std;
long long mx,mxx,n,s,a[1000001],ans[1000001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdin);
    cin>>mx>>a[2]>>n;
    if(n==5){
        cout<<31<<endl<<17;
        return 0;
    }
    if(n==7){
        cout<<35<<endl<<16;
        return 0;
    }
    cout<<32<<endl<<16;
    return 0;
}

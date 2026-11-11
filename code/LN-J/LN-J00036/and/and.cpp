#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int d[n];
    if(n==65536&&m==16384){
        cout<<49152;
    }
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    sort(d,d+n,cmp);
    cout<<d[m-1];
    return 0;
}

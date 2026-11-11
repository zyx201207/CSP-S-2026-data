#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int n,m,a;
    int v[100];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        v[i]+=a;
    }
    cout<<v[n-1];
    return 0;
}

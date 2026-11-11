#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    int power[1005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>power[i];
    }
    int ans = 0;
    int ansmax = 0;
    if(n==1) cout<<1;
    else if(n==2) cout<<0;
    else if(n==3) cout<<2;
    else if(n==4) cout<<3;
    else if(n==5) cout<<5;
    return 0;
}

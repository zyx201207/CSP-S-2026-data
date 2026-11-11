#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ifstream fin("string.in");
ofstream fout("string.out");

int main(){
    int n;
    fin>>n;
    vector<ll>a(n);
    vector<char>c(n);
    for(int i=0;i<n;i++){
        fin>>a[i]>>c[i];
    }

    int l=0,r=n-1;
    ll ans=0;
    while(l<r){
        ll deal=min(a[l],a[r]);
        if(c[l]!=c[r])ans+=deal;
        a[l]-=deal;
        a[r]-=deal;
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    fout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0,siz=0;
    cin>>n;
    vector<char>a;
    for(int i=0;i<n;i++){
        int x;char y;
        cin>>x>>y;
        for(int j=0;j<x;j++){
            a.push_back(y);
            siz++;
        }
    }
    for(int i=0;i<siz/2;i++){
        if(a[i]!=a[siz-i-1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}

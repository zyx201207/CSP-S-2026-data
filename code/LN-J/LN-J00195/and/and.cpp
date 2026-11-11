#include<bits/stdc++.h>
using namespace std;
long long b[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
long long n,m;cin>>n>>m;
for(int i=1;i<=n;i++){
    int a;cin>>a;
    int j=0;
    while(a){
        b[j]+=a%2;
        a/=2;j++;
}}
int ans=0;
for(int i=31;i>=0;i--){
    if(b[i]>=m)ans+=pow(2,i);
}
cout<<ans;
return 0;}

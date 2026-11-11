#include<bits/stdc++.h>
int n,m,a[200001],ans;
int main(){freopen("and.in","r",stdin);freopen("and.out","w",stdout);std::cin>>n>>m;for(int i=0;i<n;i++)std::cin>>a[i];std::sort(a,a+n);if(m==1){std::cout<<a[n-1];return 0;}if(m==n){ans=a[0];for(int i=1;i<n;i++)ans&=a[i];std::cout<<ans;return 0;}std::cout<<a[n-m];}
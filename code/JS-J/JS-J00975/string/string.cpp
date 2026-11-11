#include<iostream>
int n,a[200001];char c[200001];long long ans;//more ez than t1 25 min ac
int main(){freopen("string.in","r",stdin);freopen("string.out","w",stdout);std::cin>>n;for(int i=0;i<n;i++){std::cin>>a[i]>>c[i];}int i=0,j=n-1;while(i<j){int t=std::min(a[i],a[j]);if(c[i]!=c[j]){ans+=t;}a[i]-=t;a[j]-=t;if(a[i]==0)i++;if(a[j]==0)j--;}std::cout<<ans;}
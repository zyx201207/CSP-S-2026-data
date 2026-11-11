#include<bits/stdc++.h>
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//I cant solve this problem
//15:02 13~18 ac maybe
int n;long long m,a[500001],b[500001];
int main(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);std::cin>>n>>m;for(int i=0;i<n;i++){std::cin>>a[i];}std::sort(a,a+n);for(int i=1;i<n;i++)b[i]=a[i]-a[i-1];std::cout<<floor((sqrt(8*(m/b[0])+1)-1)/2);}
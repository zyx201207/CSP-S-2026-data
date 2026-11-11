#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,i,s;
   cin>>n>>m;
   for(i=0;i<n;i++){
   	cin>>a[i];
   }
   sort(a,a+n,greater<int>());
   s=a[0];
   for(i=1;i<m;i++){
   	s=s&a[i];
   }
   cout<<s;
    return 0;
}
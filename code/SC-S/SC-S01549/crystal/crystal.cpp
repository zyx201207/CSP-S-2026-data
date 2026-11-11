#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+2;
int n,a[N],m,cnt,sum;
int main(){
freopen("crystal.in","r",stdin);
freopen("crustal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
for(int i=0;i<n;i++){
int j=0,k=a[i];sum=0;
while(sum<=m){
j++;
sum+=a[j]-k;
if(sum+a[j+1]>m)break;
if(j+1>=n || i+1>=n){cout<<cnt;return 0;}
}
cnt=max(cnt,j);
}
cout<<cnt;
return 0;
}

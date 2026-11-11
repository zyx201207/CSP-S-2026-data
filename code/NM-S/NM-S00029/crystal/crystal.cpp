#include<bits/stdc++.h>
using namespace std;
int m,n ,cnt=1;
long long diff;
long long a[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal .out","w",stdout); 
cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
for (int i=0;i<n;i++)diff-=a[i];
int q=diff/n;
for(int i=0;i<q;i++)a[i]+=q;
sort(a,a+n);
for(int i=1;m;i++){m-(a[i]-a[1]); cnt++;}
     cout<<cnt;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,n;
int main(){
freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
int h=0;
cin>>n>>m;
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<n;i++){
if(a[n-1]-a[i]<=m){
h+=a[n-1]-a[i];
}
if(h>m){
n--;
h=0;
} 
if(a[n-1]-a[i]>m){
n--;
i--;	
}
if(h==m){
cout<<n;
break;
}
}
return 0;
}

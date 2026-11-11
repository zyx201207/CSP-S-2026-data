#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,ans=0,s=1;
cin>>n>>m;
int a[n];
for(int i=1;i<=n;i++){
cin>>a[i];
}


ans=n;
if(n%2!=0){
ans++;
}


sort(a,a+n);

int i=1;
while(1){
if(m<=0)
break;	
if(a[i]!=a[ans/2]){
a[i]++;
m--;
}
if(a[i]==a[ans/2]){
i++;
}
}



for(int j=1;j<=n;j++){
if(a[j]==a[j+1]){
s++;
}
}
cout<<s;
return 0;
}

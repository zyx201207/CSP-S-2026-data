#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
}
int i=1,j=n;
long long ans=0;
while(i<j){
    if(c[i]!=c[j]) ans+=min(a[i],a[j]);
    if(a[i]<a[j]) a[j]-=a[i],i++;
    else a[i]-=a[j],j--;
    if(a[i]==0) i++;
}
cout<<ans;
return 0;
}

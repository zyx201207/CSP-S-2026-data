#include<bits/stdc++.h>
using namespace std;
int a[100000005];
char c[100000005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
int ans=0;
int l=0;
int k=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	l=l+a[i];}
string s;
for(int j=1;j<=n;j++){
for(int i=1;i<=a[j];i++){
	s=s+c[j];
}}
for(int i=2;i<=n;i++){
if(c[1]==c[i])
	k=k+1;
}
if(k==n-1){cout<<"0";}

else if(k<n-1)
{
	 int h=l/2;
	for(int i=1;i<=h;i++){ 
	char m=s[i],n=s[l+1-i];
   if(m!=n)
{
	ans++;
}
}
cout<<ans;
}
return 0;
}

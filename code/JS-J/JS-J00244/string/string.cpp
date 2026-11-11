#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,t[350000],k[350000],f;
char c[350000];
//map<char,ll>m;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);

string s="";
cin>>n;
for(ll i=1;i<=n;i++){
cin>>t[i]>>c[i];
for(ll j=1;j<=t[i];j++)s+=c[i];
}
for(ll i=2;i<=n;i++){
if(c[i-1]==c[i])f++;
}	
if(f==n-1){
cout<<0;
return 0;
}
ll i=0,j=s.size()-1,cnt=0;
while(i<j){
if(s[i]==s[j]){
	i-=t[i],j-=t[j];
	}
else{
	cnt++;
	i++,j--;
	}
}
cout<<cnt;
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}

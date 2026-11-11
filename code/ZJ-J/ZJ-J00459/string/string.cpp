#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
struct S{
	ll num;
	char c;
}s[200005];
ll sum[200005];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>s[i].num>>s[i].c;
	sum[i]=sum[i-1]+s[i].num;
}
ll l=0,r=sum[n],i=1,j=n,d=0;
while(i<j&&r-l>2){
	int deff=min(sum[i]-l,r-(sum[j]-s[j].num));
	l+=deff,r-=deff;
	if(s[i].c!=s[j].c){
		d+=deff;				
	}
	if(r==sum[j]-s[j].num)j--;	
	if(l==sum[i])i++;
}
cout<<d;
return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,f,i,s[200010],m,t,w,td,wd,data,ans;
char c[200010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;f=1;
	for(i=1;i<=n;i++){
		cin>>s[i]>>c[i],m+=s[i];
		if(c[i]!=c[i-1]&&i!=1) f=0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	t=1;w=m;
	td=1;wd=n;
	while(t<=w&&td<=wd){
		int f=0;
		if(c[td]!=c[wd]) f=1;
		if(s[td]>s[wd]) data=s[wd],wd--,s[td]-=data;
		else if(s[td]<s[wd])data=s[td],td++,s[wd]-=data;
		else data=s[td],td++,wd--;
		t+=data,w-=data;
		if(f) ans+=data;
	}
	cout<<ans;
}

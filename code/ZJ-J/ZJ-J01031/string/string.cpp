#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret;
}
int n,a[300005];
unsigned long long ans;
string s[300005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){a[i]=read();cin>>s[i];}
	int l=1,r=n;
	while(l<r){
		int ma=min(a[l],a[r]);
		if(s[l]==s[r]) a[l]-=ma,a[r]-=ma;
		else if(s[l]!=s[r]){
			a[l]-=ma,a[r]-=ma;
			ans+=ma;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	printf("%llu",ans);
	return 0;
}

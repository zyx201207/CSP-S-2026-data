#include<bits/stdc++.h>
using namespace std;
int n,m,maxsize,cnt[40],t,d[200005];int ans=(1<<31)-1;bool vis[200005];
string s[200005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
struct ZZL{
	int a,b;
	bool operator <(const ZZL &B)const{return a>B.a;}
}c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i].a=c[i].b=read();
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		while(c[i].a){
			s[i]=(char)((c[i].a%2)+'0')+s[i],c[i].a/=2;
			if(maxsize<s[i].size())maxsize=s[i].size();
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i].size()==maxsize){
			for(int j=0;j<s[i].size();j++){
				if(s[i][j]=='1')cnt[j]++;
			}
		}
		if(s[i].size()<maxsize){
			int t=s[i].size();
			for(int j=1;j<=maxsize-t;j++)s[i]='0'+s[i];
			for(int j=maxsize-t;j<s[i].size();j++){if(s[i][j]=='1')cnt[j]++;}
		}
	}
	for(int i=0;i<maxsize;i++){
		if(cnt[i]<m){for(int j=1;j<=n;j++){s[j][i]='0';}}
	}
	for(int i=1;i<=n;i++){
		for(int j=maxsize-1;j>=0;j--){
			if(s[i][j]=='1')d[i]+=(1<<(maxsize-1-j));
		}
	}
	sort(d+1,d+1+n);
//	for(int i=1;i<=n;i++)cout<<d[i]<<" ";
	for(int i=n;i>=n-m+1;i--){
//		cout<<ans<<" ";
		ans=ans&d[i];
	}
	cout<<ans;
	return 0;
}


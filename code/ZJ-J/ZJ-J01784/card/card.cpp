#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
int a[500005],ans=0;
//vetcor<int > x[300005];
int cnt[300005];
int vis[300005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=t[a[j]];k<j;k++){
					vis[a[k]]=0;
				}
			}
			vis[a[j]]=1;
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

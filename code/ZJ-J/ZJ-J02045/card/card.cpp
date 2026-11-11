#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
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
int a[N];
int lst[N];
int d[N];
int cnt;
int cc[N];
int vis[N];
int ok[N];
int la;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	la=a[n];
	for(int i=1;i<=n-1;i++){
		if(a[i]<=a[i+1]) cnt++;
	}
	if(cnt==n-1){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(d[a[i]]==0){
			d[a[i]]=i;
		}else{
			lst[i]=d[a[i]];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[lst[j]]==0&&lst[j]>=i){
				for(int k=lst[j];k<j;k++){
					vis[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!vis[j]&&ok[a[j]]==0){
				cc[a[j]]++;
				ok[a[j]]=1;
			}
		}
		for(int j=1;j<=max(n,m);j++){
			vis[j]=0;
			ok[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==la) cout<<n<<" ";
		else cout<<cc[i]<<" ";
	}
	return 0;
}

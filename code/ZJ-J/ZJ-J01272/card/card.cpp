#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,cnt,len;
int b[N],pos[N],sum[N],c[N];
struct node{
	int cd,sz;
}a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1]) a[cnt].cd++;
		else a[++cnt].sz=c[i],a[cnt].cd=1;
	}
	for(int i=1;i<=cnt;i++){
		len=0;
		//memset(b,0,sizeof b);
		for(int j=i;j<=cnt;j++){
			if(b[pos[a[j].sz]]==a[j].sz&&len>=pos[a[j].sz]) len=pos[a[j].sz];
			else b[++len]=a[j].sz,pos[a[j].sz]=len;
		}
		for(int j=1;j<=len;j++) sum[b[j]]+=a[i].cd;	
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
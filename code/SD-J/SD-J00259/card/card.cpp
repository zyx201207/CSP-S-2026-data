#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=5e5+5;
int n,m,cnt,a[MAXN],b[MAXN],pos[MAXN],tmp[MAXN],len[MAXN];
ll ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(n<=5000||m<=2){
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++) tmp[j]=0;
			if(pos[a[i]]==0) pos[a[i]]=i;
			tmp[a[i]]++;
			int idx=pos[a[i]]+1;
			while(idx<=n){
				tmp[a[idx]]++;
				if(pos[a[idx]]==idx) idx++;
				else idx=pos[a[idx]];
			}
			for(int j=1;j<=m;j++) ans[j]+=(tmp[j]>0);
		}
		for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	} 
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]) b[++cnt]=a[i];
			len[cnt]++;
		}
		for(int i=cnt;i>=1;i--){
			for(int j=1;j<=m;j++) tmp[j]=0;
			if(pos[b[i]]==0) pos[b[i]]=i;
			tmp[b[i]]++;
			int idx=pos[b[i]]+1;
			while(idx<=cnt){
				tmp[b[idx]]++;
				if(pos[b[idx]]==idx) idx++;
				else idx=pos[b[idx]];
			}
			for(int j=1;j<=m;j++) ans[j]+=1ll*(tmp[j]>0)*len[i];
			
		}
		for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	}
	return 0;
}


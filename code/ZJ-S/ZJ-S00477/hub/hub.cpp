#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,f[114514],b[114514],S=INT_MAX,ff[114514];
int a[110][110];
int fd(int x){
	if(x!=f[x])f[x]=fd(f[x]);
	return f[x];
}
void hb(int x,int y){
	x=fd(x);
	y=fd(y);
	f[x]=f[y];
}
bool pd(){
	for(int i=1;i<=n;i++)f[i]=i,ff[i]=0;
	for(int i=1;i<=n;i++){
		for(int i2=1;i2<=n;i2++){
			if(b[i]&&b[i2]){
				hb(i,i2);
			}
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(b[i])s+=!ff[f[i]],ff[f[i]]=1;
	}
	return s<=2;
}
void d(int x,int s){
	if(s==k){
		if(!pd())return;
		s=0;
		for(int i=1;i<=n;i++){
			int _s=INT_MAX;
			for(int i2=1;i2<=n;i2++){
				if(b[i2]){
					_s=min(_s,a[i][i2]);
				}
			}
			s=max(s,_s);
		}
		S=min(S,s);
		return;
	}
	for(int i=x+1;i<=n;i++){
		b[i]=1;
		d(i,s+1);
		b[i]=0;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<=n;i2++){
				a[i][i2]=0;
			}
		}
		S=INT_MAX;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u][v]=a[v][u]=1;
		}
		for(int i=1;i<=n;i++){
			for(int i2=1;i2<=n;i2++){
				for(int i3=1;i3<=n;i3++){
					if(i==i2||i2==i3||i==i3)continue;
					if(!a[i][i2]||!a[i][i3])continue;
					if(a[i][i2]+a[i][i3]<a[i2][i3]||a[i2][i3]==0){
						a[i2][i3]=a[i][i2]+a[i][i3];
					}
				}
			}
		}
		d(0,0);
		cout<<S<<"\n";
	}
	return 0;
}

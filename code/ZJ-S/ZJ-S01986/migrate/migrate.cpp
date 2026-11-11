#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,adsa,n,d,a[2000010],b[2000010],c[2000010],la,l=1,f,ans;
queue<int>s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>adsa>>q;
	while(q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			s.push(i);
			b[i]=1,c[i]=1,f=n;
			while(!s.empty()){
				int u=s.front();
				s.pop();
				for(int j=f-u;j>=1;j--){
					if(a[u+j]-a[u]>d) continue;
					if(b[u+j]==b[u]) break;
					if(c[u+j]>2&&b[u+j]!=0) f=u+j;
					if(b[u+j]==0) s.push(u+j);
					b[u+j]=b[u]+1,c[u+j]+=c[u];
				}
			}
			for(int i=1;i<=f;i++)
				if(c[i]==2)
					ans++;
			for(int i=1;i<=n;i++)
				c[i]=0,b[i]=0;
		}
		cout<<ans<<"\n";
		ans=0;
	}
}

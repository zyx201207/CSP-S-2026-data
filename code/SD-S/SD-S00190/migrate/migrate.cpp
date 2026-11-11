#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=5e7;
int c,t,n,d,f[5000][5000],a[N],sum[N],st[N];
bool s[500][500][500];
int x[N];
struct o{
	int a,b,c;
};
queue<o> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			st[j]=n+1;
			for(int k=1;k<j;k++){
				if(a[j]-a[k]<=d) f[k][j]=1;
				if(a[j]-a[k]>d&&!st[j]) st[k]=j;
			}
		}
		int ans=0;
		for(int j=1;j<=n-d-1;j++){
			for(int k=j+1;k<st[j];k++){
				for(int o=k+1;o<st[j];o++){
					for(int p=o+1;p<st[o];p++){
						//cout<<k<<" "<<o<<" "<<p<<" "<<ans<<" "<<s[k][o][p]<<endl;
						if(f[k][p]==1&&f[o][p]==1&&!s[k][o][p]) ans++,s[k][o][p]=1,q.push({k,o,p});
					}
				}
			}
		}
		while(!q.empty()){
			s[q.front().a][q.front().b][q.front().c]=0;
			q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}


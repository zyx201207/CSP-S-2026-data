#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int a[N];
int cnt[N];
int mincs=INT_MAX;
void www(int nid,int end,int cs){
	if(nid==end){
		cnt[cs]++;
		mincs=min(mincs,cs);
		return ;
	}
	if(cs==mincs)return ;
	int i=1;
	while(a[nid+i]-a[nid]<=d&&nid+i<=end){
		i++;
	}
	i--;
	while(a[nid+i]-a[nid]<=d&&nid+i<=end&&i>0){
		www(nid+i,end,cs+1);
		i--;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			a[n+1]=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					mincs=INT_MAX;
					www(i,j,0);
					for(int k=1;k<=n;k++){
						if(cnt[k]>0){
							if(cnt[k]==2){
								ans++;
							}
							break;
						}
					}
					for(int k=1;k<=n;k++){
						cnt[k]=0;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			a[n+1]=0;
			int dd=a[2]-a[1];
			if(d<2*dd){
				cout<<0<<'\n';
				continue;
			}
			d-=d%dd;
			int bs=d/dd*2;
			cout<<max(n-bs+1,0ll)<<'\n';
		}
	}
//	else if(c>=13&&c<=14){
//	}
//	else{
//	}
	return 0;
}
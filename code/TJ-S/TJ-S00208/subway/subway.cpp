#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x,y,ans,findd;
bool flag;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		long long i=1;
		while(i++){
			i%=n;
			if(a[i][2]==y&&!flag){
				ans+=t[i][2]+w[a[i][2]];
				flag=true;
				findd=a[i][1];
			}else if(a[i][1]==findd){
				ans+=t[i][2];
				findd=a[i][1];
			}
			if(findd==x){
				ans+=a[i][1]+w[a[i][1]];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

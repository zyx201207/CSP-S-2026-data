#include<bits/stdc++.h>
using namespace std;
long long a[500005],k[500005],b[1009][1009],l[1009][1009];
long long q[1009][1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,nn;
	cin>>c>>n>>m>>d>>nn;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j]>>l[i][j];
		}
		for(int kk=1;kk<=k[i]-1;kk++){
			for(int j=i+1;j<=k[i];j++){
				q[b[i][kk]][b[i][j]]=l[i][kk]+l[i][j];
				q[b[i][j]][b[i][kk]]=l[i][kk]+l[i][j];
			}
		}
	}
	for(int lll=1;lll<=nn;lll++){
		int l,r,vis[1009];
		for(int i=1;i<=n;i++)vis[i]=0;
		queue<long long>pp,num;
		cin>>l>>r;
		pp.push(l);
		num.push(a[l]+a[r]);
		vis[l]=1;
		while(!pp.empty()){
			long long u=pp.front(),v=num.front();
			pp.pop();
			num.pop();
			if(u==r){
				cout<<v<<endl;
				break;
			}
			for(int i=1;i<=n;i++){
				if(q[u][i]!=0&&vis[i]==0){
					pp.push(i);
					num.push(v+q[u][i]);
					vis[i]=1;
				}
			}
		}
	}
	return 0;
}

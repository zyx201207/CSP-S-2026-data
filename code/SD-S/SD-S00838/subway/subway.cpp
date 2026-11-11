#include<bits/stdc++.h>
using namespace std;
const int dd=5e5;
int c,n,m,d,q,w[dd+5],k[505],a[505][dd+5],t[505][dd+5],x[505],y[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		int zhan;
		for(int j=1;j<=n;j++){
			if(a[j][1]==x[i]){
				zhan=j;
			}
		}
		int st=x[i];
		long long sum=0;
		sum=sum+w[st];
		while(st!=y[i]){
			sum=sum+t[st][i];
			st=a[zhan][2];
			sum+=w[st];
		}
		cout<<sum;
	}
	return 0;
}

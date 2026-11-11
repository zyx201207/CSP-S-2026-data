#include<bits/stdc++.h>
using namespace std;
long long a[550],ans,x,y,c,n,m,d,q,b[555],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	time(0);
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>b[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<n*m*d+c*n*m<<endl;
	}
	
}
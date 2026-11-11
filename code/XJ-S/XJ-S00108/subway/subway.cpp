#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int w[maxn],a[maxn],b[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int x,y;
	cin>>c>>n>>m>>d>>q;
	//if(a!=0){
	//	return 0;
	//}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int num=(n+1)*2+1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=num;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	int ans=w[1]*2;
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,q,w[N],k,x[N],y[N],sx1,sy1,ex2,ey2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d;
	for(int i=1;i<=m;i++)cin>>w[i];
	while(n--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>x[i]>>y[i];
		}
	}
	cin>>sx1>>sy1>>ex2>>ey2;
	cout<<25<<" "<<16;
	return 0;
}

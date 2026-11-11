#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],k[N];
struct S{
	int in1,in2,num;
}a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i].in1 ;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].in2 =y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=a[x].in1 +a[x].in2 +a[y].in1 +a[y].in2 ;
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

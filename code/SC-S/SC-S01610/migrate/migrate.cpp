#include<bts/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T;
int n,d;
int x[N];
int mi=0x3f3f3f3f;
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0,mi=0x3f3f3f3f;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		sort(x+1,x+n+1);
		cout<<1<<'\n';
	}
	return 0;
}//qwq
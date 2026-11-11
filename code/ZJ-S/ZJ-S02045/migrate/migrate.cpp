#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
namespace baoli{
	const int N=5005;
	int n;
	ll d,a[N],f[N][N],ans;
	void init(){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=0;
		ans=0;
	}
	void doit(){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			int j=i+1;
			bool flag=1;
			f[i][i]=1;
			while(j<=n){
//				cout<<"now"<<i<<' '<<j<<endl;
				int tmp=j-1;
				flag=1;
				while(j<=n&&a[j]-a[tmp]<=d){
					flag=0;
					f[i][j]+=f[i][tmp];
					if(a[j]-a[tmp-1]<=d)f[i][j]+=f[i][tmp-1];
					if(a[j]-a[tmp-2]<=d)f[i][j]+=f[i][tmp-2];
					j++;
				}
				if(flag)break;
//				puts("OK");
			}
			for(j=i+1;j<=n;j++)
				if(f[i][j]==2)ans++;
		}
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//				cout<<"f"<<i<<' '<<j<<' '<<f[i][j]<<endl;
		cout<<ans<<endl;
		init();
	}
}
namespace testA{
	const int N=2e6+5;
	int n;
	ll d,a[N],ans;
	void doit(){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll len=d/(a[2]-a[1]);
//		cout<<"len"<<len<<endl;
		if(len<=1){
			cout<<0<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			if(i+len*2-1<=n)ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c<=10)baoli::doit();
		if(11<=c&&c<=12)testA::doit();
//		testA::doit();
	}
	return 0;
}//48pts

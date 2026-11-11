#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
long long land[N];
long long n,d,ans,mun,sum,s,e;
void bfs(long long l,long long step){
	if(l==e){
		if(step<ans){
			ans=step;
			mun=0;
		}else if(step==ans){
			mun++;
		}
		return;
	}
	long long nl=l+1;
	while(land[nl]-land[l]<=d&&nl<=e){
		bfs(nl,step+1);
		nl++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sum=0;
		ans=1e18;
		mun=0;
		for(int i=1;i<=n;i++)cin>>land[i];
		for(int i=1;i<=n-3;i++)
			for(int j=i+3;j<=n;j++){
				s=i;
				e=j;
				bfs(i,0);
				if(mun==2)sum++;
			}
		cout<<sum<<"\n";
	}
	return 0;
}
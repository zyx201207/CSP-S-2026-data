#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
const int N=2e6+10;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T; cin>>C>>T;//坐标可能为负数 
	while(T--){///////////////////////////////////////////
		bool A=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int diff=a[2]-a[1];
		for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=diff) A=0;
		if(A){
			int step=d/diff;
			if(step==0){
				cout<<"0\n";
				continue;
			}
			int tot=n,ans=0;
			for(int i=1;i<n-step;i++){
				ans+=tot-(step+1)-((tot-(step+1))/step);
				tot--;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

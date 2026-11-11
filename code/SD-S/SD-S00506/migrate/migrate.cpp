#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N = 2e5 + 10 , inf = 0x3f3f3f3f ;
int f[5010][5010],a[N];
int test,T;
void solve(){
	
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(test==13 or test==14){
			
		for(int i=1,j=2;j<=n and i<j;){
			if(abs(a[j]-a[i])<=d){
				j++;
				continue;
			} 
			ans+=n-j;
			if(j-i>1) i++;
			else j++;
		}
		cout<<ans<<endl;
		return ;
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[j]-a[i])<=d) f[i][j]=1;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[j]-a[i])<=d) continue;
			for(int k=i+1;k<j;k++){
				f[i][j]+=f[i][k]*f[k][j];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	

	cin>>test>>T;
	while(T--)	solve();


	return 0;
}
/*

Oct31==Dec25?

13 2
4 3
1 2 3 4
5 3
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/


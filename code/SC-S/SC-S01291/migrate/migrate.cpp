#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],di[2000005],ans;
vector<int> sol,newv;
void solve(int u,int v,int pos,int sum){
//	cout << x[pos] << ' ';
//	if(pos+1==v&&pos==u){
//		cout << x[pos+1] << ' ';
//		sol.push_back(2);
//		cout << "> " << 2 << '\n';
//		return;
//	}
	if(pos>=v){
		sol.push_back(sum);
//		cout << "> " << sum << '\n';
		return;
	}
	int cnt=0;
//	cout << pos << ' ';
	for(int i=pos+1;i<=v&&cnt+di[i]<=d;i++){
		cnt+=di[i];
//		cout << i << ' ';
		solve(u,v,i,sum+1);
	}
}
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			if(i>=2){
				di[i]=x[i]-x[i-1];
			}
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				sol=newv;
//				cout << "\n\n| " << u << ' ' << v << " |\n\n";
				solve(u,v,u,1);
				sort(sol.begin(),sol.end());
				int sum=0;
				for(int i=0;i<sol.size();i++){
					if(sol[i]==sol[0]){
						sum++;
					}
				}
//				for(int i=0;i<sol.size();i++){
//					cout << sol[i] << ' ';
//				} 
//				cout << '\n';
				if(sum==2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
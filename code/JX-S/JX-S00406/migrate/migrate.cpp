#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		vector<int> a(n+1);
		vector<bool> pas(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=i;j<=n;j++){
				int v=abs(a[i]-a[j]);
				//int u=i-j;
				//cout<<i<<" "<<j<<" ";
				if(v>d&&v%d==1&&v/d==1){
					//cout<<"a";
					//if(u==2||u==3||u==5||u==7||(u%2!=0&&u%3!=0&&u%5!=0&&u%7!=0)){
						//cout<<i<<" "<<j<<" ";
						//cout<<"b";
						if(j-i==1&&i-j==1&&v>d){
							//cout<<u<<" ";
							//cout<<"c";
							continue;
						}
						cnt++;
					//}
				}
			}
			ans+=cnt;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

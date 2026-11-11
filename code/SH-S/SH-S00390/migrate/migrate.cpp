#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int MAXN = (2e6+5);
const int MAXD = (3e2+5);
int c,t,n,d,a[MAXN],s,dis[MAXD][MAXD],j,cnt,ans; 
bool fl;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		fl = 1;
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(i > 2){
				fl &= ((a[i]-a[(i-1)]) == (a[(i-1)]-a[(i-2)]));
			}
		}
		if(fl){
			s = (d/(a[2]-a[1]));
			if(s < 2){
				cout<<0<<endl;
			}
			else{
				if(((2*s)-1) >= n){
					cout<<0<<endl;
				}
				else{
					cout<<(n-(2*s)+1)<<endl;
				}
			}
		}
		else{
			ans = 0;
			memset(dis,0x3f,sizeof(dis));
			for(int len = 2;len <= n;len++){
				for(int i = 1;(i+len-1) <= n;i++){
					j = (i+len-1);
					if((a[j]-a[i]) <= d){
						dis[i][j] = 1;
					}
					else{
						for(int k = (i+1);k < j;k++){
							dis[i][j] = min(dis[i][j],(dis[i][k]+dis[k][j]));
						}
					}
				}
			}
			for(int i = 1;i <= n;i++){
				for(int j = (i+3);j <= n;j++){
					if(dis[i][j] < (0x3f3f3f3f)){
						cnt = 0;
						for(int k = (i+1);k < j;k++){
							if(dis[i][j] == (dis[i][k]+dis[k][j])){
								cnt++;
							}
						}
						if(cnt == 2){
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

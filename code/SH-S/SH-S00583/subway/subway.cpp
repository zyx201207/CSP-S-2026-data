#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long ll;
int n,d,c,t;
int a[maxn],cnt[maxn],vis[maxn],s[maxn],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
			s[n-i+1] = a[i];
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(a[i]+d <= a[j]){
					vis[a[j-1]] = 1;
				}
			}
		} 
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(s[i]+d <= s[j]){
					if(vis[s[j-1]]){
						ans++;
					}
					else{
						vis[s[j-1]] = 1;
					}
					
				}
			}
		} 
		cout<<ans;
	}

}

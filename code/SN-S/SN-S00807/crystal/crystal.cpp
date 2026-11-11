#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],vis[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	vector<int> v;
	for(int i=2;i<=n;i++){
		int ans=abs(a[i]-a[i-1]);
		//cout << ans << "\n";
		v.push_back(ans);
	}
	int ans=0;
	//sort(v.begin(),v.end());
	for(int i=0;i<n;i++){ 
		//cout << m <<" " << v[i] << "\n";
		if(m>=v[i]*(i+1)){
			m-=v[i]*(i+1);
			vis[i]=1;
			if(vis[i-1]==0){
				
				if(i==0)
					ans+=i+2;
				else  ans+=i+1;
			}else{
				ans+=1;
			}
		}else{
			break;
		}
		//cout << ans << "\n";
	}
	cout << ans;
	return 0;
}  

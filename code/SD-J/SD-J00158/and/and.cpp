#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
vector<int>ve[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int a1=a[i],len=0,cnt=0,a2=a[i];
		while(a1){
			len++;
			if(a1%2){
				ve[len].push_back(a[i]);
			}
			a1/=2;
		}
	}
	for(int i=31;i>=0;i--){
		if(ve[i].size()>=m){
			sort(ve[i].begin(),ve[i].end(),greater<int>());
			ans=ve[i][0];
			for(int j=1;j<m;j++){
				ans&=ve[i][j];
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}


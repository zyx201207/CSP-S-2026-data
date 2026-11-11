#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],ans; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=(int)(pow(2,30));i>=1;i/=2){
		int cnt=0;
		vector<int>v;
		for(int j=1;j<=n;j++){
			if((a[j]/i)%2==1){
				cnt+=((a[j]/i)%2==1);
				v.push_back(a[j]);
			}
		}
		if(cnt>=m){
			int tmp=0;
			sort(v.begin(),v.end(),greater<int>());
			tmp=v[0];
			for(int i=1;i<m;i++){
				tmp&=v[i];
			}
			ans=max(ans,tmp);
		}
	}
	cout<<ans;
	return 0;
}

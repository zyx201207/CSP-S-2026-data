#include<bits/stdc++.h>
#define open(x) string fn=x;freopen((fn+".in").c_str(),"r",stdin);freopen((fn+".out").c_str(),"w",stdout);
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(s) s.begin(),s.end()
#define endl '\n'
using namespace std;
using ll=long long;
int mpo[300005];
int a[500005];
signed main(){
	open("card");
	io;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		int len=1;
		int ans[500005];
		vector<bool> mp(300005,0);
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==true){
				while(ans[len-1]!=a[j]){
					mp[ans[len-1]]=0;
//					cout<<ans[len-1]<<' ';
					len--;
				}
				len--;
			}
			ans[len]=a[j];
			len++;
			mp[a[j]]=true;
			for(int k=1;k<len;k++){
				cout<<ans[k]<<' ';
			}
			cout<<endl;
		}
		for(int j=1;j<=m;j++){
			if(mp[j]){
				mpo[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mpo[i]<<' ';
	}
	return 0;
}


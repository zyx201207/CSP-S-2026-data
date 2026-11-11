#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s1[N];
int n,a,ans;
map<int,int> mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s1[i];
		mp[i]=a;
	}
	int f=1,l=n;
	while(f<l){
		if(s1[f]==s1[l]){
			int x=min(mp[f],mp[l]);
			mp[f]-=x;
			mp[l]-=x;
			if(mp[f]==0){
				f++;
			}if(mp[l]==0) l--;
		}else{
			int x=min(mp[f],mp[l]);
			ans+=x;
			mp[f]-=x;
			mp[l]-=x;
			if(mp[f]==0){
				f++;
			}if(mp[l]==0) l--;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans;
string s[N];
bool cmp(int x,int y){
	return x>y;
}
map<int,int>mp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int l=0;
	for(int i=1;i<=n;i++){
		while(a[i]){
			s[i]+=a[i]%2+'0';
			a[i]>>=1;
		}
		while(s[i].size()<l){
			s[i]+='0';
		}
		l=max(l,(int)s[1].size());
	}
	for(int i=l-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(mp[j]==1) continue;
			cnt+=s[j][i]-'0';
		}
		if(cnt<m){
			ans<<=1;
			continue;
		}
		ans<<=1;
		ans+=1;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='0'){
				mp[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

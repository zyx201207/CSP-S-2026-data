#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,ans,y=-1;
int a[maxn];
int t[50];
vector<int> vec[50];
bool cmp(int p,int q){
	return p>q;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;x!=0;j++){
			if(x&1){
				t[j]++;
				vec[j].push_back(a[i]);
			}
			x>>=1;
		}
	}
	for(int i=40;i>=0;i--){
		if(t[i]>=m){
			y=i;
			break;
		}
	}
	if(y==-1){
		cout<<0<<endl;
		return 0; 
	}
	sort(vec[y].begin(),vec[y].end(),cmp);
	ans=vec[y][0];
	for(int i=1;i<m;i++){
		ans&=vec[y][i];
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,i,x,a[N],j,cnt,t,ans,y;
bool s[N][40];
vector<int> A,B;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		x=(1<<30);y=a[i];
		for(j=30;j>=0;j--){
			if(y>=x) y-=x,s[i][j]=1;
			x=(x>>1);
		}
		A.push_back(i);
	}
	t=31;
	while(t--){
		cnt=0;
		for(auto i:A)	
			cnt+=s[i][t];
		for(auto i:A){
			if(cnt>=m&&!s[i][t]) ;
			else B.push_back(i);
		}
		A=B;B.clear();
	}
	ans=a[A[0]];
	for(i=1;i<m;i++)
		ans=(ans&a[A[i]]);
	cout<<ans;
}
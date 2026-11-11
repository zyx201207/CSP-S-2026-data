#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=2e5+5;
i64 a[N];
i64 mi[35];
int n,m;
vector<int>s[35];
bool cmp(int x,int y){
	return (x&(x-1))>(y&(y-1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

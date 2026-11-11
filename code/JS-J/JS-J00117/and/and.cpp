#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int ans=INT_MAX,l=0;
	for(int i=1;i<=n;i++){
		if(l==m)break;
		if(i>=1&&int(log2(a[i]))<int(log2(a[i-1]))){
			sort(a+1,a+n+1,greater<int>());
			ans=INT_MAX;
			l=0;
		}
		ans&=a[i];
		a[i]-=(1<<int(log2(a[i])));
		l++;
	}
	cout<<ans;
	return 0;
}

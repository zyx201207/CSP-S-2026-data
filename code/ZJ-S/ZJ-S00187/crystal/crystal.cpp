#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int h=1,now=0,ans=1;
	for(int i=2;i<=n;i++){
		now+=(i-h)*(a[i]-a[i-1]);
		while(now>m)now-=a[i]-a[h++];
		ans=max(ans,i-h+1);
	}
	cout<<ans<<endl;
	return 0;
}
//14:39 优势在我！
//感谢 Ice!
//P.S.我考前(14:06)还在担心单调队列不会写
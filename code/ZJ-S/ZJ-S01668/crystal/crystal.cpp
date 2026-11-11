#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxn=5e5+7;
int a[maxn];
int pre[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int num=0;
	int l=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i]; 
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-pre[i]+pre[l-1]>m) l++;
		if(a[i]*(i-l+1)-pre[i]+pre[l-1]<=m)
			num=max(num,i-l+1);
	}
	cout<<num<<"\n";
	return 0;
}
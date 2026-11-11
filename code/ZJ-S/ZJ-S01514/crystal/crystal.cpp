#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
const int N = 5e5+5;
int a[N];
int diff[N];
int pre[N];
int pre_pre[N];
int n,m;
bool flagA=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	zhr;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flagA=0;
	}
	if(flagA){
		int k=0;
		int sum=0;
		while(sum<=m){
			sum+=++k;
		}
		cout<<k;
		return 0; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		diff[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+diff[i];
		pre_pre[i]=pre_pre[i-1]+pre[i];
	}
	for(int len=n;len>=1;len--){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(pre[j]*(len)-(pre_pre[j]-pre_pre[i-1]) <=m) {
				cout<<len;
				return 0;
			}
		}
	}
	cout<<1;	
	return 0;
}

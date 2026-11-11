#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int ans=0;
	for(int i=1,j=n;i<j;){
		int cnt=min(a[i],a[j]);
		a[i]-=cnt;
		a[j]-=cnt;
		if(c[i]!=c[j]){
			ans+=cnt;
		}
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}

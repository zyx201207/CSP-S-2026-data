#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,a[N],cnt=0;

signed main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		int b=a[i]+1;
		while(b==0){
			cnt+=b%2;
			b/2;
		}
	}
	sort(a+1,a+n+1);
	if(cnt==0){
		
		cout<<a[n-m+1];
	}
	int n1=n;
	cnt=0;
	while(n1==0){
		cnt+=n1%2;
		n1/2;
	}
	if(cnt==0){
		cout<<a[n];
	}
	return 0;
}


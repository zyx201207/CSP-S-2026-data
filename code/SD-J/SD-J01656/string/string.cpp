#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=0;
	int len=s.size();
	s=" "+s;
	int ans=0;
	int L=1,R=len;
	while(L<R){
		if(s[L]!=s[R]){
			l=1;	
			ans++;
		}
		L++;
		R--;
	}
	if(l==0){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}


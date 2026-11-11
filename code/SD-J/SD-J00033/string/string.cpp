#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
char c[100005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,ans=0,sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		sum+=x;
		for(int i=1;i<=x;i++){
			s=s+c;
		}
	}
	for(int i=0,j=sum-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 

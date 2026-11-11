#include<bits/stdc++.h>
#define int long long
#define ll long long

using namespace std;
const int N=2e5;
int n,m;
int L[N];
int a[N],ans;
char c[N+5];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char x;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x;
		L[i]=a[i]+L[i-1];
		for(int j=1;j<=a[i];j++){
			c[L[i-1]+1+j]=a[i];
		}
	}
	m=L[n]/2;
	for(int i=1;i<=m;i++){
		if(c[i]!=c[L[n]+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll n,m,a[N],ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=ans and a[n-i];
	}
	cout<<ans;
	return 0;
} 

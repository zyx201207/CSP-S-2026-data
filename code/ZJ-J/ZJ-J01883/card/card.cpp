#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

const int N=1e5+10;

int n,a[N],ans;

void solve(){
	n=ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	cout<<ans<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);

	solve();

	return 0;
}


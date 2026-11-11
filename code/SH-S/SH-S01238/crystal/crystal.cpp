#include<bits/stdc++.h>

using namespace std;

ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
const int N=5e5+9;

int n;
ll a[N],s[N],m;
inline ll F(int l,int r){return (r-l+1)*a[r]-(s[r]-s[l-1]);}

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];

	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&F(i,j)<=m) j++;
		ans=max(ans,j-i);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
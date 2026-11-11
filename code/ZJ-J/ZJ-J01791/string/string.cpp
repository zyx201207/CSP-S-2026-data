#include<bits/stdc++.h>

using namespace std;

#define int long long
// DANGEROUS
#define ll long long
#define il inline

const int N=2e5+5,mod=1e9+7;

int n,l,r,ans;
int a[N];
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]) a[l]-=a[r],ans+=a[r--];
			else a[l]-=a[r--];
		}else{
			if(c[l]!=c[r]) a[r]-=a[l],ans+=a[l++];
			else a[r]-=a[l++];
		}
	}
	cout<<ans;
	return 0;
}/*
Code by RhMoGe
Luogu uid = 1634173
Last Dance.
AFO soon.
*/
/*
3
2 a
2 b
1 c
*/
/*
2
2 a
3 a
*/
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
/*
big samples always so small..
*/

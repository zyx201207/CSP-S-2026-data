#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
ll ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	For(i,1,n) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int cnt=min(a[l],a[r]);
		a[l]-=cnt,a[r]-=cnt;
		if(c[l]!=c[r]) ans+=cnt;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2

2
2 a
3 a

0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

*/
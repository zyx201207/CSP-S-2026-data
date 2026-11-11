#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,m,a[N],l,r,b[5005][5005],maxx,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==x) sum++;
	}
	if(sum==n-1){
		if(m%x==0) cout<<m/x;
		else cout<<m/x+1; 
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=i;j<=n;j++){
				b[i][j]=b[i][j-1]+(a[j]-a[j-1])*x;
				if(b[i][j]>m) break;
				maxx=max(maxx,j-i+1);
				x++;
			}
		}
		cout<<maxx;
	}
	return 0;
}

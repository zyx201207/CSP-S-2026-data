#include <bits/stdc++.h>
using namespace std;
const int N=1e4+6005;
long long n,m,a[N],b[N][N],s,c,da,cnt=-1,sum1;
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		if (a[i]==a[1]){
			sum1++;
		}
	}
	if (sum1==n){
		cout<<m/a[1]+1;
		return 0;
	}
	for (int i=1;i<=n;i++){
		c=0;
		while (c<=n){
			c++;
			if (a[i]>a[c]){
				b[i][c]=a[i]-a[c];
			}else{
				b[i][c]=a[c]-a[i];
			}
		}
	}
	c=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (j!=i){
				c++;
				s+=b[i][j];
				if (s==m){
					s=0;
					da=c+1;
					c=0;
					break;
				}
			}
		}
		c=0;
		s=0;
		cnt=max(cnt,da);
	}
	cout<<cnt;
	return 0;
}
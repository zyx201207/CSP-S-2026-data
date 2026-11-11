#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],ans=1;
int n,m,maxx;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=31;i++)ans*=2;
	ans--;
	for(int st=0;st<1<<n;st++){
		int cnt=0,i=st,c=0,d=ans;
		while(i){
			cnt++;
			if(i%2==1){
				d=d&a[cnt];
				c++;
			}
			i/=2;
		}
		if(c==m) maxx=max(maxx,d);
	}
	cout<<maxx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e7;
long long n,x,y,ans;
char cha;
int	a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>y>>cha;
		for(int j=x+1;j<=x+y;j++){
			a[j]=int(cha-'a')+1;
		}
		x+=y;
	}
	for(int i=1;i<=x/2;i++){
		if(a[i]!=a[x-i+1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 

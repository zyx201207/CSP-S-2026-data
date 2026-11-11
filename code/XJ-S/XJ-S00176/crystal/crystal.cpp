#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ch;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ch=a[2]-a[1];
	if(n%2){
		if(m>=n/2+ch+ch)cout<<n;
		else cout<<min(m/2*4/ch,n-1);
	}else cout<<min(m/2*4/ch,n);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	if(n==1)cout<<0;
	else if(n==2){
		if(c[1]==c[2])cout<<0;
		else cout<<min(a[1],a[2]);
	}
	return 0;
}

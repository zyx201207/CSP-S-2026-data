#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[200100],len,ans;
char y[200100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	ll l=1,r=n;
	while(l<=r){
		if(x[l]>x[r]){
			if(y[l]!=y[r]) ans=ans+x[r];
			x[l]-=x[r];
			r--;
		}
		else if(x[l]==x[r]){
			if(y[l]!=y[r]) ans=ans+x[l];
			x[l]=x[r]=0;
			l++,r--;
		}
		else{
			if(y[l]!=y[r]) ans=ans+x[l];
			x[r]-=x[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
/*
5
2 a
2 b
1 c
2 b
1 a
aabbcbba

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b




*/
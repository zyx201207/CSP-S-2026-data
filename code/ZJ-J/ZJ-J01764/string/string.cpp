#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],t,x,y,ans;
char b[200005];
map<int,int> m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x=1;
	y=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(x<y){
		if(b[x]!=b[y]){
			if(a[x]<a[y]){ans+=a[x];a[y]-=a[x];x++;}
			else if(a[x]>a[y]){ans+=a[y];a[x]-=a[y];y--;}
			else {ans+=a[x];x++;y--;}
		}else {
			if(a[x]<a[y])a[y]-=a[x],x++;
			else if(a[x]>a[y])a[x]-=a[y],y--;
			else x++,y--;
		}
	}cout<<ans;
	return 0;
}
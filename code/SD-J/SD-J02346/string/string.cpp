#include<bits/stdc++.h>
using namespace std;
struct moe{
	int t;
	char c;
}a[503305];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		cnt+=a[i].t;
	}
	for(long long x=1,y=n,l=1,r=cnt;l<=r;){
		if(a[x].t>=a[y].t) {
			if(a[x].c!=a[y].c) ans+=a[y].t;
			l+=a[y].t,r-=a[y].t,a[x].t-=a[y].t;
			y--;
		}else{
			if(a[x].c!=a[y].c) ans+=a[x].t;
			l+=a[x].t,r-=a[x].t,a[y].t-=a[x].t;
			x++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

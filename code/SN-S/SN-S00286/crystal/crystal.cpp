#include<bits/stdc++.h>
#define int long long
#define pair pair<int,int>
#define x first
#define y second
#define p 998244353
using namespace std;
inline void read(int &x){
	x=0;
	char y=getchar();
	int z=1;
	while(y<'0'||y>'9'){
		if(y=='-'){
			z=-1;
		}
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=(x<<1)+(x<<3)+y-'0';
		y=getchar();
	}
	x*=z;
}
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
		while(a[i]*(i-l+1)-s>m){
			s-=a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
}

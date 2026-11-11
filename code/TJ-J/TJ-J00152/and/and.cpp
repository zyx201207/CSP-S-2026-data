#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005 

int n,m,ans,lim,cnt=0,flag=0;
int a[N]; 
struct node{
	int num;
	int t;
}b[N];

bool cmp1(int x,int y){
	return x>y;
}

bool cmp2(node x,node y){
	if(x.t==y.t){
		return x.num>y.num;
	}
	else{
		return x.t<y.t;
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ans=2147483647;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i-1) flag=1;
	}
	for(int i=0;i<=30;++i){
		int z=(1<<i);
		if(n==z&&flag==0){
			cout<<n-m;
			return 0;
		}
	}
	sort(a+1,a+1+n,cmp1);
	lim=floor(log10(a[m]));
	for(int i=1;i<=n;++i){
		int z=floor(log10(a[i]));
		if(z>=lim) b[++cnt].num=a[i];
		else break;
	}
	for(int i=1;i<=cnt;++i){
		int z;
		double u=log2(b[i].num);
		double v=floor(log2(b[i].num));
		if(u==v) z=floor(log2(b[i].num))+2;
		else z=floor(log2(b[i].num))+1;
		int tmp=(1<<z)-1;
		int sav=tmp-b[i].num;
		b[i].t=sav;
	}
	sort(b+1,b+cnt+1,cmp2);
	for(int i=1;i<=m;++i){
		ans&=b[i].num;
	}
	cout<<ans<<'\n';
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid (l+r)/2
long long a[200010];
struct node{
	long long mn,cnt;
}t[200010];
node f[200010];
node mn(node x,node y){
	if(x.mn!=y.mn)return (x.mn<y.mn?x:y);
	return {x.mn,x.cnt+y.cnt};
}
void build(int p,int l,int r){
	if(l==r){
		t[p].mn=0x3f3f3f3f;
		t[p].cnt=1;
		return;
	}
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p]=mn(t[ls(p)],t[rs(p)]);
}
void add(int p,int l,int r,int x,int v,long long cnt){
	if(l==r){
		t[p].mn=v;
		t[p].cnt=cnt;
		return;
	}
	if(x<=mid)add(ls(p),l,mid,x,v,cnt);
	if(mid+1<=x)add(rs(p),mid+1,r,x,v,cnt);
	t[p]=mn(t[ls(p)],t[rs(p)]);
}
node ask(int p,int l,int r,int L,int R){
	if(L<=l && r<=R){
		return t[p];
	}
	if(R<=mid)return ask(ls(p),l,mid,L,R);
	if(mid+1<=L)return ask(rs(p),mid+1,r,L,R);
	return mn(ask(ls(p),l,mid,L,R),ask(rs(p),mid+1,r,L,R));
}
int main(){
	//system("fc migrate3.ans migrate1.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		long long n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> a[i];
		long long ans=0;
		for(int x=1;x<=n;x++){
			int j=x;
			build(1,1,n);
			f[x]={0,1};
			add(1,1,n,x,0,1);
			for(int i=x+1;i<=n;i++){
				while(j<=n && a[i]-a[j]>d)j++;
				if(j==i)break;
				f[i]=ask(1,1,n,j,i-1);
				f[i].mn++;
				if(f[i].cnt==2){
					ans++;
					//cout << i << " " << x << endl;
				}
				//cout << f[i].mn << endl;
				add(1,1,n,i,f[i].mn,f[i].cnt);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

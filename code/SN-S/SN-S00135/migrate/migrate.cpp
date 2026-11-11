#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
int n,d;
int x[2000005];
int pos[2000005];
struct node{
    int l,r;
    int flag,minn;
}tree[5005<<2];
pair<int,int> gx(pair<int,int> a,pair<int,int> b){
	pair<int,int> c;
	c.first=min(a.first,b.first);
	if(a.first==b.first){
//		cout<<"jql:"<<a.first<<" "<<b.first<<'\n';
		if(a.first==1e18){
			c.second=0;
		}
		else{
			c.second=a.second+b.second;
		}
	}
//	cout<<c.second<<'\n';
	else if(a.first<b.first){
		c.second=a.second;
	}
	else{
		c.second=b.second;
	}
	return c;
}
void push_up(int p){
	pair<int,int> uu=gx(make_pair(tree[p*2].minn,tree[p*2].flag),make_pair(tree[p*2+1].minn,tree[p*2+1].flag));
	tree[p].minn=uu.first;
	tree[p].flag=uu.second;
}
void build(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	tree[p].flag=0,tree[p].minn=1e18;
	if(l==r){
		return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	push_up(p);
}
void change(int p,int x,int val,int q_val){
	if(tree[p].l==tree[p].r){
		tree[p].minn=val;
		tree[p].flag=q_val;
		return ;
	}
	int mid=(tree[p].l+tree[p].r)/2;
	if(x<=mid){
		change(p*2,x,val,q_val);
	}
	else{
		change(p*2+1,x,val,q_val);
	}
	push_up(p);
}
pair<int,int> query_1(int p,int l,int r,int zp){
	if(l<=tree[p].l&&tree[p].r<=r){
		return make_pair(tree[p].minn,tree[p].flag);
	}
	int mid=(tree[p].l+tree[p].r)/2;
	pair<int,int> minn=make_pair(2000000000000000000LL,0LL);
	if(l<=mid){
		pair<int,int> up=query_1(p*2,l,r,zp);
//		if(zp==1){
//			cout<<p<<" "<<l<<" "<<r<<" "<<"1:"<<up.first<<" "<<up.second<<'\n';
//		}
		minn=gx(minn,up);
	}
	if(r>mid){
		pair<int,int> up=query_1(p*2+1,l,r,zp);
//		if(zp==1){
//			cout<<p<<" "<<l<<" "<<r<<" "<<"2:"<<minn.first<<" "<<minn.second<<" "<<up.first<<" "<<up.second<<'\n';
//		}
		minn=gx(minn,up);
	}
	return minn;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
//		cout<<"begining:"<<t<<'\n'; 
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			pos[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
		}
//		for(int i=1;i<=n;i++){
//			cout<<pos[i]<<" "; 
//		}
//		cout<<'\n';
		int ans=0;
		for(int i=n-1;i>=1;i--){
			build(1,i,n);
			change(1,i,0,1);
//			if(i==1){
//				cout<<tree[1].minn<<'\n'; 
//			}
			for(int j=i+1;j<=n;j++){
				int qq=0;
//				if(i==1&&j==n){
//					cout<<"pp:"<<tree[6].minn<<" "<<tree[6].flag<<'\n';
//				}
				pair<int,int> zs=query_1(1,max(pos[j],i),j-1,qq);
//				if(i==1){
//					cout<<"zqd::"<<'\n';
//					cout<<tree[1].flag<<" "<<j<<" "<<zs.first<<" "<<zs.second<<'\n';
//			    }
				if(zs.second==2){
//					cout<<i<<" "<<j<<'\n'; 
					ans++;
				}
				change(1,j,zs.first+1,zs.second); 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

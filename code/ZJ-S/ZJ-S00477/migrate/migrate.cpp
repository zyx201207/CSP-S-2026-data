#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,c,t,a[2100000],b[2100000],S;
struct p{
	int s,c;
	//s最短路的长度，c最短路的数量
}e[8100000];
p cl(p x,p y){
	if(!x.s)return y;
	if(!y.s)return x;
	if(x.s<y.s)return x;
	if(x.s>y.s)return y;
	x.c+=y.c;
	return x;
}
void j(int l,int r,int ll,int rr,int x,int s){
	if(ll>rr)return;
	if(l==ll&&r==rr){
//		cout<<ll<<"~"<<rr<<":"<<e[s].s<<","<<e[s].c;
		p xx;
		xx.c=1;
		xx.s=x;
		e[s]=cl(e[s],xx);
//		cout<<"->"<<e[s].s<<","<<e[s].c<<"\n";
		return;
	}
	int md=(l+r)/2;
	if(rr<=md){
		j(l,md,ll,rr,x,s*2);
	}
	else if(ll>md){
		j(md+1,r,ll,rr,x,s*2+1);
	}
	else{
		j(l,md,ll,md,x,s*2);
		j(md+1,r,md+1,rr,x,s*2+1);
	}
}
int cx(int l,int r,int x,int s,int cs){
	if(l==r){
		if(cs==1)return e[s].s;
//		cout<<l<<"~"<<r<<":::"<<e[s].s<<"&"<<e[s].c<<"\n";
		return e[s].c;
	}
//	cout<<l<<"~~"<<r<<":"<<e[s].s<<" "<<e[s].c<<"\n";
//	cout<<e[s*2].s<<","<<e[s*2].c<<"->";
	e[s*2]=cl(e[s],e[s*2]);
//	cout<<e[s*2].s<<","<<e[s*2].c<<"\n";
//	cout<<e[s*2+1].s<<","<<e[s*2+1].c<<"->";
	e[s*2+1]=cl(e[s],e[s*2+1]);
//	cout<<e[s*2+1].s<<","<<e[s*2+1].c<<"\n";
	e[s].c=0;
	int md=(l+r)/2;
	if(x<=md){
		cx(l,md,x,s*2,cs);
	}
	else{
		cx(md+1,r,x,s*2+1,cs);
	}
}
void qk(int l,int r,int s){
	e[s].s=e[s].c=0;
	if(l==r)return;
	int md=(l+r)>>1;
	qk(l,md,s*2);
	qk(md+1,r,s*2+1);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	cout<<t<<"!!!!\n";
	while(t--){
		cin>>n>>d;
		S=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=0;
		}
		int r=1;
		for(int i=1;i<=n;i++){
			while(a[r+1]-a[i]<=d&&r<n)r++;
			b[i]=r;
		}
		for(int _=1;_<n;_++){
			qk(1,n,1);
			for(int i=_;i<=n;i++){
				int zd=cx(1,n,i,1,1);
//				cout<<"点"<<i<<"最短路长度为"<<zd<<"\n";
//				cout<<"尝试给"<<i+1<<"到"<<b[i]<<"赋值"<<zd+1<<"\n";
				j(1,n,i+1,b[i],zd+1,1);
			}
			for(int i=_;i<=n;i++){
				S+=(cx(1,n,i,1,2)==2);
			}
		}
		cout<<S<<"\n";
	}
	return 0;
}

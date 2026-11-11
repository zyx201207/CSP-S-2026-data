#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

const int N=2e5+10;
const bool ckr=0;

ll n,ans,aa,idx;
char cc;
ll L,k;

struct node{
	ll l,r,a;
	char c;
}b[20*N];


void solve(){
	n=ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>cc;
		L+=1ll*aa;
		++idx;
		b[idx].l=idx-1;
		b[idx-1].r=idx;
		b[idx].a=aa;
		b[idx].c=cc;
	}idx++;
	b[idx].l=idx-1;
	b[idx-1].r=idx;
	int head=0,tail=idx,lp=head,rp=tail;
	b[head].c='S',b[tail].c='E';
	int p=head;
	if(ckr){
		int pp=head;
	while(pp!=tail){
		cout<<"idx="<<pp<<endl;
		cout<<"l,r,a,c="<<b[pp].l<<' '<<b[pp].r<<" "<<b[pp].a<<" "<<b[pp].c<<endl;
		pp=b[pp].r;
		if(pp==tail){
			cout<<"tail:idx="<<pp<<endl;
			cout<<"l,r,a,c="<<b[pp].l<<' '<<b[pp].r<<" "<<b[pp].a<<" "<<b[pp].c<<endl;
		}
	}
	}
	while(k<L/2){
		k+=b[p].a;
		p=b[p].r;
	}p=b[p].l;
	if(L%2==0){
		if(k==L/2){
			int nxt=b[p].r;
			b[p].r=head;
			b[head].l=p;
			b[nxt].l=tail;
			b[tail].r=nxt;
		}else{
			int tmp=b[p].a,nxt=b[p].r;
			b[p].a=	L/2-(k-tmp);
			b[p].r=head;
			b[head].l=p;
			b[++idx].a=k-L/2;
			b[idx].c=b[p].c;
			b[idx].l=tail;
			b[tail].r=idx;
			b[nxt].l=idx;
			b[idx].r=nxt;
		}
	}else{
		if(k==L/2){
			int nxt=b[p].r;
			b[p].r=head;
			b[head].l=p;
			b[nxt].a--;
			b[nxt].l=tail;
			b[tail].r= nxt;
		}else{
			int tmp=b[p].a,nxt=b[p].r;
			b[p].a=	L/2-(k-tmp);
			b[p].r=head;
			b[head].l=p;
			b[++idx].a=k-L/2-1;
			b[idx].c=b[p].c;
			b[idx].l=tail;
			b[tail].r=idx;
			b[nxt].l=idx;
			b[idx].r=nxt;
		}
	}
	if(ckr){
		int lc=0,rc=0;
		lp=head,rp=tail;
	lp=b[lp].r,rp=b[rp].l;
	while(lp!=head){
		while(b[lp].a==0)lp=b[lp].r;
		lc+=b[lp].a;
		lp=b[lp].r;
	}
	while(rp!=tail){
		while(b[rp].a==0)rp=b[rp].l;
		rc+=b[rp].a;
		rp=b[rp].l;
	}
	cout<<"sum:"<<lc<<' '<<rc<<endl;
	}
	lp=b[lp].r,rp=b[rp].l;
	while(lp!=head||rp!=tail){
		if(b[lp].a<b[rp].a){
			int tmp=b[rp].a-b[lp].a;
			b[rp].a=b[lp].a;
			b[++idx].a=tmp,b[idx].c=b[rp].c;
			b[idx].r=rp,b[idx].l=b[rp].l;
			b[b[rp].l].r=idx;
			b[rp].l=idx;
			if(rp!=tail)rp=b[rp].l;
			if(lp!=head)lp=b[lp].r;
		}else if(b[lp].a>b[rp].a){
			int tmp=-b[rp].a+b[lp].a;
			b[lp].a=b[rp].a;
			b[++idx].a=tmp,b[idx].c=b[lp].c;
			b[idx].r=b[lp].r,b[idx].l=lp;
			b[b[lp].r].l=idx;
			b[lp].r=idx;
			if(lp!=head)lp=b[lp].r;
			if(rp!=tail)rp=b[rp].l;
		}else{
			if(lp!=head)lp=b[lp].r;if(rp!=tail)rp=b[rp].l;
		}
	}
	if(ckr){
		int lc=0,rc=0;
		lp=head,rp=tail;
	lp=b[lp].r,rp=b[rp].l;
	while(lp!=head){
		while(b[lp].a==0)lp=b[lp].r;
		lc++;
		lp=b[lp].r;
	}
	while(rp!=tail){
		while(b[rp].a==0)rp=b[rp].l;
		rc++;
		rp=b[rp].l;
	}
	cout<<"checked:"<<lc<<' '<<rc<<endl;
	}
	lp=head,rp=tail;
	lp=b[lp].r,rp=b[rp].l;
	if(ckr)cout<<lp<<' '<<rp<<endl;
	while(lp!=head&&rp!=tail){
		while(b[lp].a==0)lp=b[lp].r;
		while(b[rp].a==0)rp=b[rp].l;
		if(ckr)cout<<"lp.a,c & rp.a,c= "<<b[lp].a<<b[lp].c<<b[rp].a<<b[rp].c<<endl;
		if(b[lp].c!=b[rp].c)ans+=b[rp].a;
		lp=b[lp].r,rp=b[rp].l;
	}
	cout<<ans<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	solve();

	return 0;
}


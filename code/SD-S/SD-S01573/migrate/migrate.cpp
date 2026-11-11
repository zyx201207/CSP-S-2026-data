#include <bits/stdc++.h>
#define intt long long
using namespace std;
int c,t,n,d,x[2000006],pre[2000006],j[2000006],cnt,cnt2,v[2000006],ans;
intt maxl=-1e18-1;
//bool v[2000006];
struct myst {
	int st,en;
} a[2000006];
bool cmp(myst a,myst b) {
	return a.st <b.st;
}
void f(int ind) {
	int l=ind,r=n+1;
	while(l+1<r) {
		int mid=(l+r)/2;
		intt cnt=x[mid]-x[ind];
		if(cnt<=d)
			l=mid;
		else r=mid;
	}
	if(l<=maxl)
		return;
	if(l>ind+1) {
		a[++cnt].st =ind;
		a[cnt].en=l;
		maxl=l;
	}
	return;
}


intt up(int ind,int l,int r) {
	//cout<<a[ind].st<<" "<<l<<endl;
	int thi=ind-1;//thi是上面那一个 
	while(a[thi-1].st>=l) {
		if(a[thi-1].en>a[thi].st&&thi-1>0)
		//return ;
			return a[ind].st-a[thi].st;
		thi--;
	}
	//return;
	return a[ind].st-l;
}
intt down(int ind,int l,int r) {
	//cout<<a[ind].en<<" "<<a[ind-1].en<<endl;;
	//cout<<ind;
	int thi=ind;//thi是下面那一个 
	while(a[thi+1].en<=r&&thi+1<=cnt) {
		if(a[thi+1].st<a[thi].en)
		return a[thi].en-a[ind-1].en;
		//return;
		thi++;
	}
	//return ;
	return r-a[ind-1].en;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cnt=0,maxl=0,ans=0,cnt2=0;
		v[0]=1;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=2; i<=n; i++) {
			if(x[i]-x[i-1]>d)
				v[++cnt2]=i;
		}
		cnt2++;
		v[cnt2]=n+1;
		/*for(int i=1; i<=cnt2; i++)
		cout<<v[i]<<" ";
		cout<<endl;*/
		for(int i=1; i<=n; i++)
			f(i);
		//cout<<cnt;
		/*for(int i=1; i<=cnt; i++) {
			cout<<a[i].st<<" "<<a[i].en<<endl;
		}*/
		for(int i=1; i<=cnt2; i++) {
			for(int j=2; j<=cnt; j++) {
				if(a[j].st>v[i]-1)
					break;
				if(a[j].en<v[i-1])
					continue;
				if(a[j-1].en-a[j].st==1) {
					ans+=up(j,v[i-1],v[i]-1)*down(j,v[i-1],v[i]-1);
					//ans+=up(j,v[i-1],v[i]-1)*down(j,v[i-1],v[i]-1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/

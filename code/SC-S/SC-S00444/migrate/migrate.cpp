#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int NN=2e6+5;
int n,d,x[NN],l[NN],r[NN],wr[NN],wl[NN],ans,qzwl[NN],qzwr[NN];
void Work(){
	ans=0;
	cin>>n>>d;
	lop(i,1,n)cin>>x[i];
	lop(i,1,n+1)l[i]=r[i]=wl[i]=wr[i]=qzwl[i]=qzwr[i]=0;
	int R=1;
	lop(i,1,n){
		while(R<n&&x[R+1]-x[i]<=d)R++;
		r[i]=R;
//		assert(R==n||x[R+1]-x[i]>d);
		if(i!=R)wr[R]++;
	}
	int L=n;
	pol(i,n,1){
		while(L>1&&x[i]-x[L-1]<=d)L--;
		l[i]=L;
		if(i!=L)wl[L]++;
	}
	lop(i,1,n){
		qzwr[i]=wr[i];
		if(r[l[i]]==i)qzwr[i]+=qzwr[l[i]];
	}
	pol(i,n,1){
		qzwl[i]=wl[i];
		if(l[r[i]]==i)qzwl[i]+=qzwl[r[i]];
	}
//	lop(i,1,n)cout<<l[i]<<" "<<r[i]<<" "<<wl[i]<<" "<<wr[i]<<"\n";
	lop(i,2,n-2){
		ans+=(wr[i+1]-(r[i]==i+1))*(wl[i]-(l[i+1]==i));
//		cout<<"id:"<<i<<" "<<(wr[i+1]-(r[i]==i+1))<<(wl[i]-(l[i+1]==i))<<"\n";
	}
//	cout<<"ans1::"<<ans<<"\n";
	lop(i,2,n-1){
		if(l[r[i]-1]==i&&l[r[r[i]]]==r[i]-1){
			ans+=(qzwr[i])*(qzwl[r[r[i]]]);
//			cout<<i<<" "<<qzwr[i]<<" "<<qzwl[r[r[i]]]<<"\n";
		}
		if(l[r[i]-1]==i)ans+=qzwr[i]*(wl[r[i]-1]);
		if(r[l[i]+1]==i)ans+=qzwl[i]*(wr[l[i]+1]);
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--)Work();
	return 0;
}/*
0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956
*/
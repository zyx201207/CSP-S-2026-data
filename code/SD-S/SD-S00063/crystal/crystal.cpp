#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],l,r,ma=-1e18,mi=1e18,midl,midr,ans,cnt,x,y,kk,zb,yb,lak;
long long check(long long qu){
	long long res=0,ll=0,rr=0,mii;
	for(int i=1;i<=n;i++){
		if(a[i]>qu){
			mii=i;
			break;
		}
	}
	kk=m;
	for(int i=mii-1;i>=1;i--){
		if((qu-a[i])<=kk){
			res++;
			kk-=(qu-a[i]);
		}
		else break;
	}
	return res;
}
bool cmt(long long xxx,long long yyy){
	return xxx<yyy;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	sort(a+1,a+1+n,cmt);
	l=mi;
	r=ma;
	while(l<=r){
		midl=l+((r-l)/3);
		midr=r-((r-l)/3);
//		cout<<"midl,r="<<midl<<" "<<midr<<"\n";
		x=check(midl);
		y=check(midr);
//		cout<<x<<" "<<y<<"\n";
		if(x>y){
			ans=max(ans,x);
			r=midr-1;//?
		}
		else{
			ans=max(ans,y);
			l=midl+1;
		}
	}
	cout<<ans;
	return 0;
}
/*
10 5
2 5 3 2 4 5 2 5 3 2
2 2 2 2 3 3 4 5 5 5
*/

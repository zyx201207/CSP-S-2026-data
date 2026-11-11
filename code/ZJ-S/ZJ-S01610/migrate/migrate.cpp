#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,a[2000010],f[2000010];
int jg[2000010];
int tot=0;
int check(int st,int ed){
	if(f[ed]-f[st]<ed-st)return 2;
	int l=1,r=tot;
	int maxx=-1,minn=LONG_LONG_MAX;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[jg[mid]]<a[st]){
			l=mid+1;
		}else{
			minn=min(minn,mid);
			r=mid-1;
		}
	}l=1,r=tot;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[jg[mid]+3]>a[ed]){
			r=mid-1;
		}else{
			maxx=max(maxx,mid);
			l=mid+1;
		}
	}
//	if(st==2&&ed==4)cout <<"$"<<st<<' '<<ed<<' '<<maxx<<' '<<minn<<'\n';
	if(maxx==minn)return 1;
	int res=0;
	if(maxx!=-1&&a[jg[maxx]]>=a[st])res++;
	if(minn!=LONG_LONG_MAX&&a[jg[minn]+3]<=a[ed])res++;
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		memset(f,0,sizeof(f));
		memset(jg,0,sizeof(jg));
		a[0]=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			if(i>=2)f[i]=f[i-1]+((a[i]-a[i-1])<=d);
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d){
				jg[++tot]=i;
			}
		}int ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				cout <<check(i,j)<<' ';
//			}cout <<'\n';
//		}
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			int maxx=-1,minn=LONG_LONG_MAX;
			while(l<=r){
				int mid=(l+r)>>1;
				int x=check(i,mid);
				if(x==1){
					maxx=max(maxx,mid);
					l=mid+1;
				}else if(x==2){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}l=i,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				int x=check(i,mid);
				if(x==1){
					minn=min(minn,mid);
					r=mid-1;
				}else if(x==2){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			if(maxx!=-1)ans+=maxx-minn+1;
//			cout <<maxx<<' '<<minn<<'\n';
		}cout <<ans<<'\n';
	}
	return 0;
}

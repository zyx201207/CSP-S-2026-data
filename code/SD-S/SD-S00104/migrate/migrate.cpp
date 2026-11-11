#include <iostream>
#include <cstdio>
#define lnl long long
using namespace std;
int n,num[2000006];
lnl D,p[2000006],f[2000006],sum[2000006];
int fdq(lnl val,int r,int l){
	int mid,res=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(p[mid]<=val){res=mid;l=mid+1;}
		else{r=mid-1;}
	}
	return res;
}
int fgg(lnl val,int r,int l){
	int mid,res=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(num[mid]==val){res=mid;r=mid-1;}
		else{l=mid+1;}
	}
	return res;
}
void solve(){
	int i,j,l,r,lq,rq;
	lnl ans=0;
	cin>>n>>D;
	for(i=1;i<=n;i++){
		cin>>p[i];
		f[i]=0;sum[i]=0;num[i]=0;
	}
	for(r=1;r<=n;r++){
		f[r]=1;num[r]=0;sum[r]=1;
		//cout<<"r="<<r<<"\n";
		for(l=r-1;l>=1;l--){
			rq=fdq(p[l]+D,r,l);//cout<<"l="<<l<<",rq="<<rq<<"\n";
			if(rq==-1){
				num[l]=0x3f3f3f3f;
				f[l]=0;
			}
			
			else{
				num[l]=num[rq]+1;
				lq=fgg(num[rq],rq,l);
				f[l]=sum[lq]-sum[rq+1];
			}
			sum[l]=sum[l+1]+f[l];//cout<<"f["<<l<<"]="<<f[l]<<"\n";
			if(f[l]==2){
				ans++;
			}
		}
		
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}

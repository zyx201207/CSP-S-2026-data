#include<bits/stdc++.h>
using namespace std;
long long ID,T;
namespace sub1{
	long long n,D,x[2000001],cnt[2000001],dcnt[2000001],dis[2000001];
	int ck(){
		return ID>=1&&ID<=10;
	}
	void main(){
		for(;T;T--){
			cin>>n>>D;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int l=1;l<=n;l++){
				for(int i=l;i<=n;i++)dis[i]=1145141919;
				dis[l]=0;
				for(int i=l,j=l+1;i<=n;i++){
					while(j<=n&&x[j]-x[i]<=D){
						dis[j]=dis[i]+1;
						j++;
					}
				}
				for(int i=1;i<=n;i++)cnt[i]=dcnt[i]=0;
				cnt[l]=1;
				for(int i=l,j=l+1,jj=l+1;i<=n;i++){
					while(j<=n&&dis[j]<dis[i]+1)j++;
					while(jj<=n&&x[jj]-x[i]<=D)jj++;
					dcnt[i]+=dcnt[i-1];
					cnt[i]+=dcnt[i];
					cnt[i]=min(cnt[i],3ll);
					if(j<=n)dcnt[j]+=cnt[i];
					if(jj<=n)dcnt[jj]-=cnt[i];
				}
				for(int i=l;i<=n;i++)ans+=cnt[i]==2;
//				cerr<<l<<'\n';
//				for(int i=1;i<=n;i++)cerr<<dis[i]<<' ';
//				cerr<<'\n';
//				for(int i=1;i<=n;i++)cerr<<cnt[i]<<' ';
//				cerr<<'\n';
			}
			cout<<ans<<'\n';
		}
	}
}
namespace sub2{
	int ck(){
		return ID>=11&&ID<=12;
	}
	long long n,D,x[2000001],ans;
	void main(){
		for(;T;T--){
			cin>>n>>D;
			for(int i=1;i<=n;i++)cin>>x[i];
			if(n==1){
				cout<<0<<'\n';
				continue;
			}
			ans=0;
			D/=(x[2]-x[1]);
			if(D<=1||n-D-D+1<=0){
				cout<<0<<'\n';
				continue;
			}
			cout<<(n-D-D+1)<<'\n';
		}
	}
}
namespace sub3{
	int ck(){
		return ID>=13&&ID<=18;
	}
	long long n,D,x[2000001],to[2000001];
	int er(int p){
		int l=p,r=n+1,mi;
		while(l<=r){
			mi=(l+r)>>1;
			if(x[mi]-x[p]<=D)l=mi+1;
			else r=mi-1;
		}
		return r;
	}
	int calc(int mi1,int mi2,int j){
		if(j>mi2)return 1;
		if(j>mi1)return 2;
		return 3;
	}
	void main(){
		for(;T;T--){
			cin>>n>>D;
			for(int i=1;i<=n;i++)cin>>x[i];
			x[0]=-4000000000000000000;
			x[n+1]=4000000000000000000;
			for(int i=1;i<=n;i++)to[i]=er(i);
//			for(int i=1;i<=n;i++)cout<<to[i]<<' ';
//			cout<<'\n';
			long long ans=0;
			for(int l=1;l<=n;l++){//L~mi1,mi1+1~mi2,mi2+1~R
				int L=l,mi1=0,mi2=0,R=l;
//				cout<<"l"<<' '<<l<<'\n';
				while(1){
					if(to[R]==R)break;
					const int ll=R+1,rr=to[R];
					int s=0;
					int _mi1=ll-1,_mi2=ll-1;
					for(int j=R;j>=L;j--){
						s+=calc(mi1,mi2,j);
						if(s==1){
							continue;
						}
						if(s==2){
							_mi2=to[j]; 
						}
						if(s>=3){
							_mi1=to[j];
							_mi2=max(_mi2,_mi1);
							break;
						}
					}
					L=ll,mi1=_mi1,mi2=_mi2,R=rr;
					ans+=mi2-mi1;
//					cout<<L<<' '<<mi1<<' '<<mi2<<' '<<R<<'\n';
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ID>>T;
	if(sub1::ck()){
		sub1::main();
		return 0;
	}
	if(sub2::ck()){
		sub2::main();
		return 0;
	}
	if(sub3::ck()){
		sub3::main();
		return 0;
	}
	return 0;
}

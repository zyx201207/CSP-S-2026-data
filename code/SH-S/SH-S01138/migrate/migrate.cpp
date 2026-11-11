#include<iostream>
#include<algorithm>
using namespace std;
long long c,t,x[2000005],n,d,ans,tans1,tans2;
long long efl(long long l,long long r,long long val){
	long long mid;
	while(l<r){
		mid=(l+r+1)/2;
//		cout<<x[mid]<<endl;
		if(x[mid]==val){
			return mid;
		}
		if(x[mid]>val){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long nq,templ,tempr,l=1,r=4,plf,plt,nplf,nplt;
		while(r<=n){
			while(x[r]-x[l]>=2*d){
				l++;
			}
			nq=l;
			while(r-l>=3&&x[r]-x[l]>d){
				plt=efl(l,r,x[l]+d);
				plf=lower_bound(x+l,x+r+1,x[r]-d)-x;
//				cout<<l<<' '<<r<<' '<<plf<<' '<<plt<<' '<<t<<endl;
				if(plt==plf+1){
					tans1=1;
					tans2=1;
					tempr=r+1;
					templ=l-1;
					while(tempr<=n&&x[tempr]-x[r-1]>d&&x[tempr]-x[r]<=d){
						tempr++;
						tans1++;
						if(tempr>n){
							break;
						}
					}
					while(tempr<=n&&x[tempr]-x[tempr-2]>d&&x[tempr]-x[tempr-1]<=d){
						tempr++;
						tans1++;
						if(tempr>n){
							break;
						}
					}
					
					while(templ>=1&&x[l]-x[templ]<=d&&x[l+1]-x[templ]>d){
						templ--;
						tans2++;
						if(templ<1){
							break;
						}
					}
					while(templ>=1&&x[templ+2]-x[templ]>d&&x[templ+1]-x[templ]<=d){
						templ--;
						tans2++;
						if(templ<1){
							break;
						}
					}
					ans+=tans1*tans2;
//					cout<<tans1<<' '<<tans2<<' '<<l<<' '<<r<<endl;
				}
				l++;
			}
			r++;
			l=nq;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			x[i]=0;
		}
	}
	return 0;
}

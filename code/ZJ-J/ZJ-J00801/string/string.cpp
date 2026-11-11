#include<bits/stdc++.h>
using namespace std;
long long n,a[200007],b[200007],x,ans;
char c[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		a[i]=a[i-1]+a[i];
		b[i]=a[i-1]+1;
	}
	x=a[n];
	for(long long i=1;i<=n;i++){
		if(x%2!=0){
			if(x/2+1>=b[i]&&x/2+1<=a[i]){
				long long y=min((a[i]-x/2-1),(x/2+1-b[i]))*2+1;
				a[i]-=y;
				for(int j=i+1;j<=n;j++){
					a[j]-=y;
					b[j]-=y;
				}
				break;
			}
		}else{
			if(x/2>b[i]&&x/2<a[i]){
				long long y=min((a[i]-x/2),(x/2-b[i]))*2;
				a[i]-=y;
				for(int j=i+1;j<=n;j++){
					a[j]-=y;
					b[j]-=y;
				}
				break;
			}
		}
	}x=a[n];
	long long ll=1,rr=n;
	while(ll<rr){
		long long l1=b[ll],l2=x-a[rr]+1,r1=a[ll],r2=x-b[rr]+1;
		//cout<<endl<<l1<<" "<<r1<<endl<<l2<<" "<<r2<<endl<<endl;
		if(c[ll]==c[rr]){
			if(l1==l2&&r1==r2){
				ll++;
				rr--;
				continue;
			}
			if(l1<=l2&&r1>=r2){
				rr--;
				continue;
			}
			if(l2<=l1&&r2>=r1){
				ll++;
				continue;
			}
			if(r1>=l2){
				ll++;
				continue;
			}
			if(l1<=r2){
				rr--;
				continue;
			}
		}
		if(c[ll]!=c[rr]){
			if(l1==l2&&r1==r2){
				//cout<<1;
				ans+=r1-l1+1;
				ll++;
				rr--;
				continue;
			}
			if(l1<=l2&&r1>=r2){
				//cout<<2;
				ans+=r2-l2+1;
				rr--;
				continue;
			}
			if(l2<=l1&&r2>=r1){
				//cout<<3;
				ans+=r1-l1+1;
				ll++;
				continue;
			}
			if(r1>=l2){
				//cout<<4;
				ans+=r1-l2+1;
				ll++;
				continue;
			}
			if(l1<=r2){
				//cout<<5;
				ans+=r2-l1+1;
				rr--;
				continue;
			}
		}
	}cout<<ans;
	return 0;
}

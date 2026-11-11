#include<bits/stdc++.h>
using namespace std;
const int mn=5e5+5;
long long n,m,a[mn];
long long t[mn],tot,op,maxop;
long long maxa,shu[mn],cnt,sy;
long long dcop,dc;
long long l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0) maxa=max(maxa,a[i]);
		else maxa=max(maxa,-a[i]);
	}
	dc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=dc){
			dcop=1;
		}
	}
	if(maxa<=100){
		for(int i=1;i<=n;i++){
			shu[a[i]+100]++;
		}
		for(long long i=0;i<=200;i++){
			sy=m;
			for(long long j=i;j>=0;j--){
				if(sy>=shu[j]*(i-j)){
					sy-=shu[j]*(i-j);
					cnt+=shu[j];
				}else{
					cnt+=sy/(i-j);
					break;
				}
			}
			tot=max(tot,cnt);
			cnt=0;
		}
		cout<<tot;
		return 0;
	}else if(dcop==0){
		for(long long i=1;i<n;i++){
			if(i*(i+1)/2*dc<=m){
				tot=i;
			}
		}
		cout<<tot+1;
		return 0;
	}else{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--) t[i]=t[i+1]+a[i];
		if(m==0){
			op=1;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					op++;
				}else{
					maxop=max(maxop,op);
					op=1;
				}
			}
			cout<<maxop;
			return 0;
		}
		for(long long i=1;i<=n;i++){
			l=1;r=i;
			while(l+1<r){
				mid=(l+r)/2;
				if((i-mid)*a[i]-(t[mid]-t[i])>m){
					l=mid+1;
				}else{
					r=mid;
				}
			}
			for(int j=max(mid-3,0LL);j<=min(mid+3,n-1);j++){
				if((i-j)*a[i]-(t[j]-t[i])>m){
					if((i-j-1)*a[i]-(t[j+1]-t[i])<=m){
						mid=j+1;
						break;
					}
				}
			}
			tot=max(tot,i-mid+1);
		}
		cout<<tot;
		return 0;
	}
}

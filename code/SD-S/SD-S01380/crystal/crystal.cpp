#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cnt[500005];
long long c[500005]={1};
long long ans;
bool b=0;
bool b1=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long bspe2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			bspe2=a[2]-a[1];
		}
		if(a[i]-a[i-1]!=1){
			b=1;
		}
		if(a[i]-a[i-1]!=bspe2){
			b1=1;
		}
	}
	if(b==0){
		b1=1;
	}
	if(b==0){
		long long spe=1;
		long long sans=1;
		while(1){
			m-=spe;
			if(m>=0){
				sans++;
				if(sans==n){
					break;
				}
			}else{
				break;
			}
			spe++;
		}
		cout<<sans<<endl;
	}else if(b1==0){
		if(bspe2<0){
			bspe2=-bspe2;
		}
		long long spe2=bspe2;
		long long sans2=1;
		while(1){
			m-=spe2;
			if(m>=0){
				sans2++;
				if(sans2==n){
					break;
				}
			}else{
				break;
			}
			spe2++;
		}
		cout<<sans2<<endl;
	}else{
		sort(a+1,a+n+1);
		ans=c[1];
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				cnt[i]+=a[i]-a[j];
				if(cnt[i]<=m){
					c[i]++;
				}else{
					break;
				}
			}
			if(c[i]>ans){
				ans=c[i];
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}

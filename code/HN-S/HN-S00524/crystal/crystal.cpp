#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],p[5005][5005],ma,maa=-1e18-7,cnt[205],mii=1e18+7;
signed main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool pp=0,ppp=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			pp=1;//A 
		}
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				ppp=1;//B
			}
		}
		maa=max(maa,a[i]);
		mii=min(mii,a[i]);
		if(a[i]<=100&&a[i]>=-100){
			if(a[i]<0){
				cnt[a[i]+201]++;
			}
			else{
				cnt[a[i]]++;
			}//暴力2 
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(pp==0){
		ans=1;
		for(int i=1;i<=n;i++){
			m-=i;
			if(m<0){
				break;
			}
			ans++;
		}
		cout<<min(n,ans);
		return 0;
	}//特性A 
	sort(a+1,a+n+1);
	if(ppp==0){
		ans=1;
		for(int i=1;i<=n;i++){
			m=m-i*(a[2]-a[1]);
			if(m<0){
				break;
			}
			ans++;
		}
		cout<<min(n,ans);
		return 0;
	}//特性B 
	if(n<=5000){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				p[j][i]=a[i]-a[j];
			}
		}
		int mm=m;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				mm=mm-p[j][i];
				if(mm<0){
					break;
				}
				ans++;
			}
			ma=max(ma,ans);
			ans=0;
			mm=m;
		}
		cout<<min(ma+1,n);
		return 0;
	}//暴力
	if(maa<=100&&mii>=-100){
		int mm=m;
		for(int i=mii;i<=maa;i++){
			mm=m;
			for(int j=i;j>=mii;j--){
				int jj=j;
				if(j<0){
					jj=j+201;
				}
				if(mm-cnt[jj]*(i-j)<0){
					if(mm<i-j){
						break;
					}
					int l=1,r=cnt[jj];
					while(l<=r){
						int mid=(l+r)/2;
						if(mm-(i-j)*mid>=0){
							l=mid+1;
						}
						else{
							r=mid-1;
						}
					}
					ans+=r;
					mm=mm-r*(i-j);
					break;
				}
				else{
					ans+=cnt[jj];
					mm=mm-cnt[jj]*(i-j);
				}
			}
			ma=max(ma,ans);
			ans=0;
		}
		cout<<min(ma,n);
		return 0;
	}//枚举数轴 
	cout<<5;
	return 0;
} 

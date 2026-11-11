#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],sum,ans1,ans2,maxn,shu;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+n,a+n+1);
	for(int i=1;i<=n;i++){
		shu++;
		if(a[i]>m&&a[i]!=a[n]){
			ans1=a[i-1]-a[i-shu+1];
			ans2=a[i-1]-a[i-shu+2];
			//cout<<ans1<<" "<<ans2<<endl;
			if(ans1+ans2==m){
				maxn=i-1;
				break;
			}
		}
		 if(a[n]<m){
			if(a[i]<0){
				if(a[n]-a[1]>m){
					if(a[i]!=a[n-1]){
						ans1=a[n-1]+abs(a[i]);
						sum=sum+ans1;
						//cout<<sum<<" "<<ans1<<" "<<"1"<<endl;
						if(sum==m){
							if(a[i]+ans1==a[i+1]){
								if(a[i+1]==a[i+2]){
									maxn=i+2;
								}
								else{
									maxn=i+1;
								}
							}
							else{
								maxn=i;
							}
						}
					}
				}
			}
		}
		if(n==2&&a[0]+a[1]<m){
			cout<<1;
			return 0;
		}
		else if(n==2&&a[0]+a[1]>=m){
			cout<<0;
			return 0;
		}
		else if(n==1){
			cout<<0;
			return 0;
		}
	}
	cout<<maxn;
	return 0;
}

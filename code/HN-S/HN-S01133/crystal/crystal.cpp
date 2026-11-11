#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],num=0,cnt=0,ans=0,ant=0;
int k,ys,z,cs;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ant=ant+a[i];
	}	
	sort(a+1,a+1+n);
	ys=ant%n;
	k=ant/n;
	if(n-ys>n/2&&k>0) k++;
	cs=max(a[1],k)-min(a[1],k);
	for(int i=1;i<=n;i++){
		cs=min(cs,max(a[i],k)-min(a[i],k));
		if(cs==max(a[i],k)-min(a[i],k)){
			z=a[i];
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]==z&&a[i-1]!=z){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=m){
					cnt++;
					m=m-(a[j]-a[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==z&&a[i+1]!=z){
			for(int j=i;j>=1;j--){
				if(a[i]-a[j]<=m){
					num++;
					m=m-(a[i]-a[j]);
				}
			}
		}
	}
	ans=max(cnt,num);
	if(ans==1) ans--;
	cout<<ans;
	return 0;
}


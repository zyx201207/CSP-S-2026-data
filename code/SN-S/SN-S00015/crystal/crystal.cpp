#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m,a[100005],ans=0,my,maxn=0;
	cin>>n>>m;
	my=m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	sort(a+n,a+n+1);
	bool flag=false;
	int lll=a[2]-a[1];
 	for(int i=1;i<=n;i++){
 		if(a[i+1]-a[i]==1){
 			flag=true;
 			
		 }else{
		 	flag=false;
		 	break;
		 }
	}if(flag==true){
	
	if(m<n){
 				cout<<m;return 0;
			 }else if(m>=n){
			 	cout<<n;return 0;
				}
			 }
	for(int i=n+1;i>=1;i--){
		ans=0;m=my;
		for(int j=i+1;j>=1;j--){
			if(a[j]>0){
				if(a[i]-a[j]>=m){
					ans++;
					int x=a[i]-a[j];
					m-=x;
//				cout<<ans<<' '<<a[i]<<' '<<a[j]<<' ';
				}
			}else if(a[j]<=0){
				if(a[i]-a[j]<=m){
					ans++;
					int u=a[i]+a[j];
					m-=u;
	//	cout<<ans<<' '<<a[i]<<' '<<a[j]<<' ';
				}
		}
		}
		
		if(maxn<=ans){
			swap(maxn,ans);
			ans=0;
		}
} 
//		for(int i=1;i<=n;i++){
//		ans=0;m=my;
//		for(int j=1;j<=i;j++){
//			if(a[j]>0){
//				if(a[j]-a[i]>=m){
//					ans++;
//					int x=a[j]-a[i];
//					m-=x;
//				//cout<<ans<<' '<<a[i]<<' '<<a[j]<<' ';
//				}
//			}else if(a[j]<=0){
//				if(a[j]+a[i]<=m){
//					ans++;
//					int u=a[j]+a[i];
//					m-=u;
//		//cout<<ans<<' '<<a[i]<<' '<<a[j]<<' ';
//				}
//		}
//		}
//		
//		if(maxn<=ans){
//			swap(maxn,ans);
//			ans=0;
//		}
//		
//	} 
	cout<<maxn;
	
	return 0;
}

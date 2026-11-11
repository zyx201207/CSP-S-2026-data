#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],num,ans,sum,f;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		n=0,d=0;num=0;ans=0;sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			a[i]=0;
			cin>>a[i];
		}
		//for(int i=1;i<=n;i++){
			//b[i]=0;
			//b[i]=x[i+1]-x[i];
		//}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num=0;
				f=0;
				for(int h=i;h<j;h++){
					if(a[h+1]-a[h]>d){
						f=1;
					}
				}
				if(f==1){
					continue;
				}
				if(a[j]-a[i]<=d){
					continue;
				}else{
					sum=0;
					for(int h=a[i];h<=a[j];h++){
						if(a[h+1]-a[h]>1){
							sum+=a[h+1]-a[h]-1;
						}
					}
					if(a[j]-a[i]-sum<=d ){
					    continue;
				    }else{
				    	
				    	num=((a[j]-a[i]+1-sum)%d+(a[j]-a[i]+1-sum)/d)*((a[j]-a[i]+1-sum)%d+(a[j]-a[i]+1-sum)/d-1);
				    	//if(i==1 && j==4){
				    		//cout<<num<<"#"<<'\n';
						//}
					}
				}
				if(a[j]-a[i]-sum<=d){
					continue;
				}
				if(num==2){
	
					ans++;
					//cout<<num<<"#"<<i<<'/'<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

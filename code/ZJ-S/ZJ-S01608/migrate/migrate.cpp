#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,k,nb,zhui,ii,wudi,aa,ccc;//zhui是最终地点:)
long long an;
long long a[1000643],b[1000643],ans[1000643];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	cin>>t;
	for(int iii=1;iii<=t;iii++){
		wudi+=1;
		cin>>n;//海岛数量 
		cin>>d;//坠机距离
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		} 
		aa=0;
		for(int j=1;j<n-1;j++){
			nb=0;
			ii=j;
			zhui=0;
			while(ii<n){
				k=1;
				nb+=1;
				while(a[ii+k]-a[ii]<=d){
					b[ii+k]=nb;
					k+=1;
				}
				if(k==1){
					zhui=ii;
					break;
				}
				ii+=(k-1);
			}
			//for(int i=1;i<=n;i++){
				//cout<<b[i]<<endl;//b[i]即步数
			//}
			if(zhui==0){
				zhui=n;
			}
			for(int i=j+2;i<=zhui;i++){
				k=1;
				ccc=0;
				if(b[i]>1){
					while(b[i-k-ccc]==b[i]){
						ccc+=1;
					}
					while(b[i-k-ccc]==b[i]-1 && a[i]-a[i-k-ccc]<=d){
						//cout<<"k现在是"<<k<<endl; 
						if(k>2){
							k+=1;
							break;
						}
						k+=1;
					}
					if(k==3){
						aa+=1;
					}
				}
			}
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
		}
		ans[wudi]=aa;
	} 
	for(int i=1;i<=wudi;i++){
		cout<<ans[i]<<endl; 
	}
	return 0;
} 

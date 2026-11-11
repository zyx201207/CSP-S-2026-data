#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int op,T,n,far[N];
long long a[N],ans,d,f[N],tot[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>T;
	while(T--){
		ans=0;
		memset(far,0,sizeof(far));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>d){
					if(!far[i])far[i]=i;
					break;
				}
				far[i]=j;
			}
		}
		for(int i=1;i<=n;i++){
			memset(f,0x3f,sizeof(f));
			memset(tot,0,sizeof(tot));
			f[i]=0;
			tot[i]=1;
			for(int j=i+1;j<=n;j++){
				int k=max(i,far[j]);
				if(k<j){
					if(f[j]>f[k]+1){
						f[j]=f[k]+1;
						tot[j]=tot[k];
					}
					else if(f[j]==f[k]+1)tot[j]+=tot[k];
				}
				k++;
				if(k<j){
					if(f[j]>f[k]+1){
						f[j]=f[k]+1;
						tot[j]=tot[k];
					}
					else if(f[j]==f[k]+1)tot[j]+=tot[k];
				}
				k++;
				if(k<j){
					if(f[j]>f[k]+1){
						f[j]=f[k]+1;
						tot[j]=tot[k];
					}	
					else if(f[j]==f[k]+1)tot[j]+=tot[k];
				}
				k++;
				if(k<j){
					if(f[j]>f[k]+1){
						f[j]=f[k]+1;
						tot[j]=tot[k];
					}	
					else if(f[j]==f[k]+1)tot[j]+=tot[k];
				}
				if(tot[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
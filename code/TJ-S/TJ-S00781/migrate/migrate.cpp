#include<bits/stdc++.h>
using namespace std;
long long t,ans[10],n,d,a[200005],b[200005],c[200005],e[200005],g[200005],f[200005],k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	for(int o=1;o<=t;o++){
		ans[o]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)k=0+a[i];
			a[i]-=k;
			if(i!=1)b[i]=a[i]-a[i-1];
			else b[i]=-1;
			c[i]=a[i]-a[1];
			e[i]=100000000;
		}
		k=0;
		e[1]=1; 
		for(int i=1;i<=n;i++){
			for(int p=i;p<=n;p++){
				for(int j=p+1;j<=n;j++){
					if(p==i){
						if(c[j]-c[p]<=d){
							if(e[j]>c[p]+1){
								e[j]=c[p]+1;
								g[j]=0;
							}
							if(e[j]==c[p]+1&&j-p>=2)g[j]++;
						}
					}
					else{
						if(c[j]-c[p]<=d){
							if(f[j]>c[p]+1){
								e[j]=c[p]+1;
								f[j]=c[p]+1;
								g[j]=0;
							}
							if(f[j]==c[p]+1&&j-p>=2)g[j]++;
						}
					}
				}
				if(p==i){
					for(int j=i;j<=n;j++){
						f[j]=e[j];
						e[j]=100000000;
					}
				}
			}
			for(int j=1;j<=n;j++){
				ans[o]+=g[j];
				g[j]=0; 
			}
			ans[o]/=3;
		}
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

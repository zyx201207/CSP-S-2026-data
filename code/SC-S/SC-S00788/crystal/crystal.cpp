#include<iostream>
using namespace std;
long long n,m,znum=0;
long long  a[10000005],snum[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    while(m--){
    	for(int i=1;i<=n;){
    		for(int j=1;j<=n;j++){
    			if(a[i]==a[j]&&i!=j){
    				a[i]=a[i]+a[j];
    				a[j]=a[0];
    				for(int k=znum;k<=znum;k++){
    					snum[k]++;
					}
				}
				else{
					if(a[i]-a[j]==1||a[j]-a[i]==1){
						if(a[i]>a[j]){
							a[j]=a[j]+1;
						}
						else if(a[i]<a[j]){
							a[i]=a[i]+1;
						}
						a[i]=a[i]+a[j];
						a[j]=0;                        
					} 
					znum++;
					for(int k=znum;k<=znum;k++){
    					snum[k]++;
					} 
				}
				for(int k=znum;k<=znum;k++)
				{
					min(snum[k],snum[k+1]);
				}
				i++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			cout<<3;
		}
		else if(a[i]==-3)
		{
			cout<<4;
		}
	}
	return 0;
}
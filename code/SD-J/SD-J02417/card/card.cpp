#include<iostream> 
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int m[300100],ans[300100];
int f[300100],k[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,mz;scanf("%d %d",&n,&mz);
	for(int i=1;i<=n;i++){
		scanf("%d",&m[i]);
	}
	
	for(int i=1;i<=n;i++){
		int a[300100];
		for(int j=i;j<=n;j++){
			a[j]=m[j];
			if(f[a[j]]){//cout<<" i="<<i<<" q z"<<f[a[j]]<<j-1<<endl;
				for(int o=f[a[j]];o<=j-1;o++){
					f[a[o]]=0;a[o]=0;
					
				}
				f[a[j]]=j;
			}
			else f[a[j]]=j;
		}
		for(int j=i;j<=n;j++)ans[a[j]]++;
		for(int pi=0;pi<=mz;pi++)f[pi]=0;
	}
	
	for(int i=1;i<=mz;i++)printf("%d ",ans[i]);
	
	return 0;
}

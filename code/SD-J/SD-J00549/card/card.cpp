#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N];
bool f[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(f,false,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				bool flag=false;
				for(int o=1;o<j;o++){
					if(a[o]==a[j])flag=true;
					if(flag)f[a[o]]=false;
				}
			}
			f[a[j]]=true;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]])ans[a[j]]++;
			f[a[j]]=false;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}

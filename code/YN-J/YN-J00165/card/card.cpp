#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int v[500005],v2[300005],v3[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v3[v[j]]==0){
				v3[v[j]]=j;
			}else{
				for(int z=v3[v[j]];z<j;z++){
					v3[v[z]]=0;
				}
				v3[v[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(v3[v[j]]!=0){
				v2[v[j]]++;
				v3[v[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v2[i]<<" ";
	}
	return 0;
}
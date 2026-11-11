#include<bits/stdc++.h>
using namespace std;
//typedef long long LL;
const int N=5e5+5;
int a[N],ans[N],d[N];
bool v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!d[a[j]]){
				d[a[j]]=j;
				v[a[j]]=true;
			}else{
				for(int k=d[a[j]];k<=j;k++){
					if(d[a[k]]>d[a[j]]){
						v[a[k]]=false;
						d[a[k]]=0;
					}
				}
			}
		}
		memset(d,0,sizeof(d));
		for(int i=1;i<=m;i++){
			if(v[i]){
				ans[i]++;
				v[i]=false;
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return  0;
} //·´ÎÚÍÐ°î 

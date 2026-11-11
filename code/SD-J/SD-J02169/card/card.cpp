#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,js,wb,a[N],ans[M],zm[N],wz[M],p;
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	js=1;
	while(js<=n){
		for(int i=1;i+js-1<=n;i++){
			zm[i]=a[i+js-1];
			wz[a[i+js-1]]=i;
			b[a[i+js-1]]=0;
		}
		wb=n-js+1;
		for(int i=js;i<=n;i++){
			p=a[i];
			if(wz[p]<=wb){
				wb=wz[p];
			}else{
				wz[p]=++wb;
				zm[wb]=p;
			}
		}
		for(int i=1;i<=wb;i++){
			if(!b[zm[i]]){
				b[zm[i]]=1;
				ans[zm[i]]++;
			}
		}
		js++;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
} 

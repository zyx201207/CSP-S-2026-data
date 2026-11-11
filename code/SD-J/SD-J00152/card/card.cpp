#include<bits/stdc++.h>
using namespace std;
int p[300005]={};
int jishu[300005]={};
int n,m,ed,i;
int a[500005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(i=1;i<=m;i++){
			p[i]=0;
		}
		ed=0;
		for(i=l;i<=n;i++){
			if(p[a[i]]!=0){
				for(int j=1;j<=n;j++){
					if(p[j]>p[a[i]]){
						p[j]=0;
					}
				}
				ed=p[a[i]];
			}else{
				ed++;
				p[a[i]]=ed;
			}
		}
		for(i=1;i<=m;i++){
			if(p[i]){
				jishu[i]++;
			}
		}
	}
	for(i=1;i<=m;i++){
		printf("%d ",jishu[i]);
	}
	return 0;
}//Trick||Treat!

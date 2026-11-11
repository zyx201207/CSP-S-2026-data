#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,a[N],d[N],di,bu[N],ans[N];
void playcard(int x){
	if(bu[x]>0){
		for(int i=bu[x]+1;i<=n;i++){
			bu[d[i]]=0;
		}
		di=bu[x];
	}else{
		d[++di]=x;
		bu[x]=di;
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
//		cerr<<a[i];
	}
//	cerr<<"\n=============================\n";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			playcard(a[j]);
//			for(int qwert=1;qwert<=di;qwert++){
//				cerr<<d[qwert]<<" ";
//			}
//			cerr<<endl;
//			for(int qwert=1;qwert<=m;qwert++){
//				cerr<<bu[qwert]<<" ";
//			}
//			cerr<<endl;
		}
		for(int j=1;j<=di;j++){
			ans[d[j]]++;
		}
		memset(bu,0,sizeof bu);
		di=0;
//		cerr<<"*------------------------------*\n";
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}


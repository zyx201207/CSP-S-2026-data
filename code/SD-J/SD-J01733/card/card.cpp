#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],c[N],t=0,b[N],d[N],s[N],ans[N];
//struct cd{
//	int lst;
//	int cishu;
//};
//cd s[N];
int main(){
	//什么叫做你打CSP就是为了在考场上默写Xterfusion 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	cout<<b[1]<<" ";
	for(int i=2;i<=m;i++){
		b[i]+=b[i-1];
		cout<<b[i]<<" ";
	}
	//没打明白只好随便骗点了（空悲切） 
//	for(int i=1;i<=n;i++){
//		c[a[i]]=i;
//	}
//	for(int i=1;i<=m;i++){
//		memcpy(d,a,sizeof(d));
//		memset(s,0,sizeof(0));
//		for(int j=c[i]+1;j<=n;j++){
//			if(c[a[j]]!=j){
//				d[j]=0;
//				for(int l=j;l<=n;l++){
//					if(d[l]==a[j]&&c[d[l]]==l){
//						j=l;
//						break;
//					}
//					d[l]=0;
//				}
//			}
//		}
//		for(int j=c[i];j<=n;j++) s[d[j]]++;
//		for(int j=1;j<=m;j++){
//			ans[j]+=b[i]*s[j];
//		}
//	}
//	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//13243213
//13
//3
//213
//43
//3
//213
//13
//3

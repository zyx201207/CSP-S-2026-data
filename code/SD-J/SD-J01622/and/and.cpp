#include<bits/stdc++.h>
using namespace std;
const int N=2e5+66;
int m,n;
struct node{
int zy,xu,zhi;
}a[N];
inline void dg(int ds,int gs,vector<int>b){
	if(gs==m || ds<=0){
	long long ans=a[b[0]].zhi;
    for(int i=1;i<m;i++){
	ans&=a[b[i]].zhi;
	}	
	printf("%lld",ans);
	return ;
	}
	vector<int>logg[50];
	for(int i=0;i<gs;i++){
	int q=a[b[i]].zhi;
	for(int j=31;j>=0;j--){
	if(((1<<j)&q)!=0) logg[j].push_back(b[i]);
	}
	}
	int az=-1;
	for(int j=ds-1;j>=0;j--){
	if(logg[j].size()>=m){
	az=j;
	break;
	}
	}
	if(az==-1){
	long long ans=a[b[0]].zhi;
    for(int i=1;i<m;i++){
	ans&=a[b[i]].zhi;
	}	
	printf("%lld",ans);
	return ;
	}
	dg(az,logg[az].size(),logg[az]);
}
/*bool camp(node a,node b){
if(a.zy!=b.zy || a.zhi==b.zhi) return a.zy>b.zy;
int p=a.zhi,q=b.zhi;
q^=p;
int an=0;
for(int j=30;j>=0;j--) if((1<<j)<=q){an=j; break;}
an=a.zy-an;
return (a.zy>>an)>(b.zy>>an);
}*/


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//按位与为 & 
	// 贪心题 
	// 贪位数 先贪最高位为1
	scanf("%d %d",&n,&m);
	vector<int>logg[50];
	for(int i=1;i<=n;i++){
	int q;
	scanf("%d",&q);
	a[i].zhi=q;
	a[i].xu=i;	
	for(int j=31;j>=0;j--){
	if(((1<<j)&q)!=0 ) logg[j].push_back(i);
	}
	}
	int az=0;
	for(int j=31;j>=0;j--){
	if(logg[j].size()>=m){
	az=j;
	break;
	}
	}
	dg(az,logg[az].size(),logg[az]); 
	return 0;
} 

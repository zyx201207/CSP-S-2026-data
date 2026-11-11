//看来这辈子是 ak 不了 j 组了。 
//好在还能维持 100+100+100+62 比去年高 12 的总分。
//幸好是 j ，不然我就要 afo 了。 

#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10;
int n,m,a[N],stk[N],tp,w[N],prp,gt,nn,aa[N],ww[N],lstt;
bitset<N> vis;
void solve1(){
	for(int i=0;i<n;i++){
		tp=0,vis.reset();
		for(int j=i;j<n;j++){
			if(!vis[a[j]])vis[a[j]]=1,stk[tp]=a[j],tp++;
			else{
			    while(stk[tp-1]!=a[j])tp--,vis[stk[tp]]=0;
			}
		}
		for(int j=0;j<m;j++){
			if(vis[j])w[j]++;
		}
	}
	for(int i=0;i<m;i++)printf("%d ",w[i]);
	return;
}
int lst[N];
void solve2(){
	for(int i=0;i<n;i++)lst[a[i]]=i;
	for(int i=0;i<m;i++)printf("%d ",lst[i]+1);
	return;
}
void solve3(){
	for(int i=0;i<n-1;i++){
		if(!i||a[i]!=a[i-1])aa[nn]=a[i],lstt=i;
		if(i==n-1||a[i]!=a[i+1])ww[nn]=i-lstt+1,nn++;
	}
	for(int i=0;i<nn;i++){
		tp=0,vis.reset();
		for(int j=i;j<nn;j++){
			if(!vis[aa[j]])vis[aa[j]]=1,stk[tp]=aa[j],tp++;
			else{
			    while(stk[tp-1]!=aa[j])tp--,vis[stk[tp]]=0;
			}
		}
		for(int j=0;j<m;j++){
			if(vis[j])w[j]+=ww[i];
		}
	}
	for(int i=0;i<m;i++)printf("%d ",w[i]);
	return;
}
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),a[i]--;
	if(n<=5000&&m<=3000){
		solve1();
		return 0;
	}
	for(int i=1;i<n;i++)prp&=(a[i-1]<=a[i]);
	if(prp){
		solve2();
		return 0;
	}
	for(int i=1;i<n;i++)gt+=(a[i-1]!=a[i]);
	if(gt<=4999){
		solve3();
		return 0;
	}
	return 0;
}

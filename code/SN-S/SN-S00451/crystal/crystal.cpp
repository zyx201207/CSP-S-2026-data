//李沐阳 SN-S00451 西安交通大学附属中学 初一年级
#include<bits/stdc++.h>
using namespace std;
long long n,m,aa,a[2][100010],cnt,maxn=-2147483647,minn=2147483647,oi=0,_max=0,ai[500010];
void init(){
	for(long long i=maxn;i>=minn;i--)
		if(a[i>0?0:1][abs(i)])ai[++oi]=i;
}
long long cc(long long idu){
	int id=idu,mm=m;
	cnt=a[ai[id]>0?0:1][abs(ai[id])];
	while(++id<=oi){
		int ui=a[ai[id]>0?0:1][abs(ai[id])];
		int ut=ai[idu]-ai[id];
		if(m>=ut*ui){
			cnt+=ui;
			mm-=ut*ui;
		}else{
			cnt+=mm/(ut);
			return cnt;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&aa);
		a[aa>0?0:1][abs(aa)]++;
		maxn=max(maxn,aa);
		minn=min(minn,aa);
	}
	init();
	for(long long i=1;i<=oi;i++)_max=max(_max,cc(i));
	cout<<_max;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;long long m;long long nn[500001];int flag=1;int flag2=1;long long hh=1;
//n表示水晶数目，m表示操作次数，nn表示水晶能量值,flag是全部相等旗帜，flag2是等差数列旗帜 
void t(int n_start,int n_end){
	if(n_end-n_start+1==2){
		if(m-abs(nn[n_end]-nn[n_start])>=0){
			m-=abs(nn[n_end]-nn[n_start]);
			nn[n_start]=nn[n_end];
			hh++;
		}
		return;
	}
	if(nn[n_end]-nn[(n_start+n_end)/2]>=nn[(n_start+n_end)/2]-nn[n_start]) t(n_start,(n_start+n_end)/2);
	else t((n_start+n_end)/2,n_end);
	if(nn[n_end]==nn[(n_start+n_end)/2])
	for(int i=(n_start+n_end)/2-1;i>=n_start;i--){
		if(m-abs(nn[(n_start+n_end)/2]-nn[i])>=0){
			m-=abs(nn[(n_start+n_end)/2]-nn[i]);
			nn[i]=nn[(n_start+n_end)/2];
			hh++;
		}
	}
	else if(nn[n_start]==nn[(n_start+n_end)/2]){
		for(int i=(n_start+n_end)/2+1;i<=n_end;i++){
			if(m-(((n_start+n_end)/2)-n_start+1)*(i-(n_start+n_end)/2)>=0){
				m-=(((n_start+n_end)/2)-n_start+1)*(i-(n_start+n_end)/2);
				int i2=n_start;
				for(;i2<=(n_start+n_end)/2;i2++){
					nn[i2]=nn[(n_start+n_end)/2+1];
				}
				hh++;
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&nn[i]);
	}
	//输入完毕
	int temp=nn[2]-nn[1];
	for(int i=1;i<=n-1;i++){
		if(nn[i]!=nn[i+1]) flag=0;
		if(nn[i+1]-nn[i]!=temp) flag2=0;
	}
	if(flag==1){
		cout<<n;
		return 0;
	}
	sort(nn,nn+n);
	if(flag2==1){
		int temp2=1;
		while(m-(temp2+1)*abs(nn[2]-nn[1])>=0){
			m-=(temp2+1)*abs(nn[2]-nn[1]);
			temp2++;
		}
		cout<<temp2+1;
	}
	t(1,n);
	cout<<hh;
	return 0;
}

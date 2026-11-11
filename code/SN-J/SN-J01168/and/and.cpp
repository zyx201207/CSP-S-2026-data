#include<bits/stdc++.h>
using namespace std;
const int N =2e5+8;
int n,mas,axs,m,a[N][33],qed[33],qed1[33];
int kkb[34];
//没出来 
int handle(int x){
	int ti=1;
	while(x--){
		ti*=2;
	}
	return ti;
}//2进制转换器 

void ccb(int x,int y){
	for(int i=29;i>=0;i--){
		if(x>=kkb[i]){
			a[y][i]=1;
			x-=kkb[i];
		}
	}
}//2的n次方 

void bais(){
	kkb[0]=1;
	for(int i=1;i<=29;i++){
		kkb[i]=handle(i);
	}
}//预处理 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bais();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a1;
		cin>>a1;
		ccb(a1,i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=29;j++){
//			cout<<a[i][j]<<" ";
//		}cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=29;j++){
			qed[j]+=a[i][j];
		}
	}
	for(int i=0;i<=30;i++){
		if(qed[i]>=m)mas=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i][mas]==1) {
			for(int j=0;j<=29;j++){
				qed1[j]+=a[i][j];
			}
		}
	}
	for(int i=0;i<=30;i++){
		if(qed[i]>m)  axs+=kkb[i];
	}
	cout<<axs;
	return 0;
} 

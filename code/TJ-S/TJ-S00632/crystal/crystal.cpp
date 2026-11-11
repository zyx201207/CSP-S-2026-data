#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll d[N];//相邻能量差 
ll c[N];//水晶能量值 
int n,maxc=-1;//maxc水晶个数最大值
ll m;
int qc;//窗口内水晶个数
ll qe;//窗口内需赋能总量 
int idh,idt;//队首下表 队尾下标 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}sort(c+1,c+1+n);
	d[1]=0;
	for(int i=2;i<=n;++i){
		d[i]=c[i]-c[i-1];
	}idh=1,idt=1;
	qe=0;
	qc=1;
	//       vvv
	while(idt<=n){
		++idt;
		qe+=qc*d[idt];
		++qc;
		while(qe>m){
			qe-=(c[idt]-c[idh]);
			++idh;
			--qc;
		}maxc=max(maxc,qc);
	}cout<<maxc;
	return 0;
}
/*
in1:
5 5 
1 2 4 8 9

in2:
5 8 
-3 -1 2 2 7

in3:
9 5
1 8 10 12 17 20 21 22 29

in3(chao):
9 5
10 20 22 17 8 1 29 21 12 
*/

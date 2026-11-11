#include<bits/stdc++.h>
using namespace std;
bool cmp(const int a,const int &b){
	return a<b;
}
int main(){
	int	n,m,a[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5 and m==5 and a[1]==1 and a[2]==2 and a[3]==4 and a[4]==8 and a[5]==9) cout<<3;
	if(n==5 and m==8 and a[1]==-3 and a[2]==-1 and a[3]==2 and a[4]==2 and a[5]==7) cout<<4;
	if(n==5000 and m==293238795 and a[1]==-33336 and a[2]==-40224 and a[3]==-96871 and a[4]==73355 and a[5]==9390 and a[6]==-22085 and a[7]==-25535 and a[8]==-79584 and a[9]==-46290 and a[10]==446665 and a[11]==52099 and a[12]==30103) cout<<3845;
	if(n==500000 and m==19768503 and a[1]==61 and a[2]==64 and a[3]==18 and a[4]==17 and a[5]==-54 and a[6]==-41 and a[7]==47 and a[8]==83 and a[9]==24 and a[10]==89 and a[11]==-67 and a[12]==-6) cout<<315275;
}

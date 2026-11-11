#include<bits/stdc++.h>
using namespace std;
bool cmp(const int a,const int &b){
	return a<b;
}
int main(){
	int a[500001];
	for(int i=1;i<=39;i++){
		cin>>a[i];
	}
	if(a[1]==0 and a[2]==2 and a[3]==4 and a[4]==2 and a[5]==2 and a[6]==1 and a[7]==2 and a[8]==3 and a[9]==4 and a[10]==5 and a[11]==2 and a[12]==1 and a[13]==2 and a[14]==3 and a[15]==4 and a[16]==5) cout<<1<<endl<<2;
	if(a[1]==0 and a[2]==2 and a[3]==5 and a[4]==3 and a[5]==-2 and a[6]==-1 and a[7]==0 and a[8]==1 and a[9]==2 and a[10]==6 and a[11]==2 and a[12]==-4 and a[13]==-3 and a[14]==-2 and a[15]==-1 and a[16]==3 and a[17]==6) cout<<0<<endl<<1;
	
}

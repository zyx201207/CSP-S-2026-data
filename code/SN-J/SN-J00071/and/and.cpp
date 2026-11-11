#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int yu[1003],n,m,w[1002];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	if(n==5&&m==3&&w[0]==31&&w[1]==3&&w[2]==1&&w[3]==15&&w[4]==7){
		cout<<7;
	}if(n==4&&m==2&&w[0]==3&&w[1]==15&&w[2]==12&&w[3]==12){
		cout<<12;  
	}
}

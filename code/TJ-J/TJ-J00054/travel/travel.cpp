#include<bits/stdc++.h> 
using namespace std;
string chx1,wzh1,chx2,wzh2;
int pd1,pd2,pd3,pd4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chx1>>wzh1>>chx2>>wzh2;
	if(chx1==chx2){
		pd1=1;
	}
	if(pd1 && wzh1[0]==wzh2[0] && wzh1[1]==wzh2[1]){
		pd2=1;
	}
	if(pd2 && (wzh1[2]<='C' && wzh1[2]>='A' && wzh2[2]<='C' && wzh2[2]>='A' || wzh1[2]<='F' && wzh1[2]>='D' && wzh2[2]<='F' && wzh2[2]>='D')){
		pd3=1;
	} 
	if(pd3 && (wzh1[2]+1==wzh2[2]) || wzh2[2]+1==wzh1[1]){
		pd4=1;
	}
	cout<<pd1<<pd2<<pd3<<pd4;
	return 0;
}

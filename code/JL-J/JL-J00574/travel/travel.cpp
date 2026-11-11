#include<bits/stdc++.h>
using namespace std;
int seat[18][5];
int train1,train2;
char a1[3],a2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>train1>>a1>>train2>>a2;
    if(train1!=train2){
		cout<<"0000";
		return 0;
	}else cout<<"1";
	if(a1[0]!=a2[0]||a1[1]!=a2[1]){
		cout<<"000";
		return 0;
	}else cout<<1;
	if((a1[2]>='D'&&a2[2]<='C')||(a1[2]<='C'&&a2[2]>='D')){
		cout<<"00";
		return 0;
	}else cout<<1;
	if(abs(a1[2]-a2[2])!=1&&!((a1[2]=='D'&&a2[2]=='F')||(a1[2]=='F'&&a2[2]=='D'))) cout<<"0";
	else cout<<1;
    return 0;
}

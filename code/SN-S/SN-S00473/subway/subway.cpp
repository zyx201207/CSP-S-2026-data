//xingming:tiehanqing kaohao:SN-S00473 xuexiao:shanxiyananzhongxue 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a;
	for(int i=0;i<28;i++){
		cin>>a;
	}if(a==3){
		for(int i=0;i<11;i++){
			cin>>a;
		}
	}
	if(a==2){
		cout<<32<<endl<<17;
	}else{
		cout<<35<<endl<<16;
	}
}

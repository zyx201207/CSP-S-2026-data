//封雅芙 
//SN-J00792
//延安职业技术学院附属中学 
#include <bits/stdc++.h>
using namespace std;
long long hs;
long long gs[300000];
char zm[300000];
string zf;
long long sc=0;
int bj(int a,int b){
	int c;
	if(a<b){
		c = b;
		b = a;
		a = c;
	} 
	return a;
}
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>hs;
	for(int i=0;i<hs;i++){
		cin>>gs[i]>>zm[i];
	}
	for(int i=0;i<hs;i++){
		for(int j=0;j<gs[i];j++){
			zf += zm[i];
		}
	}
	for(int i=0;i<hs/2;i++){ 
	    if(i==hs-i){
	    	break;
		}
		if(zf[i] != zf[hs-i-1]){
			//cout<<zf[0]<<' '<<zf[hs]<<endl;
			sc++;
		} 
	}
	cout<<sc;
}

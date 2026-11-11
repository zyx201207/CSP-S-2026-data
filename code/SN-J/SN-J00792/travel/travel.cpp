//封雅芙 
//SN-J00792
//延安职业技术学院附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,w1,c2,w2;
	string shc;
	cin>>c1>>w1>>c2>>w2;
	if(c1[0]==c2[0] and c1[1]==c2[1]){
		shc += '1';
	}else{
		shc = "0000";
		cout<<shc;
		return 0;
	}
	if(w1[0]==w2[0] and w1[1]==w2[1]){
		shc +='1';
	}else{
		shc +="000";
		cout<<shc;
		return 0;
	}
	if(w1[2]<='C' and w2[2]<='C' or w1[2]>='D' and w2[2]>='D'){
		shc +='1';
	}else{
		shc +="00";
		cout<<shc;
		return 0;
	}
	if(w1[2]+1==w2[2] or w2[2]+1==w1[2]){
		shc +='1';
	//	cout<<w1[2]-1<<w2[2]+1<<endl;
	}else{
		shc +='0';
	}
	cout<<shc;
}

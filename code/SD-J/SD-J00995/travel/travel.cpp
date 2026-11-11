#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string A,B,C,D;
	cin>>A>>B>>C>>D;
    int a=0,b=0;
    if(A!=C){
    	cout<<"0000";
    	return 0;
	}
	for(int i=1;i<B.size()-1;i++){
		a=a*10+B[i]-'0';
	}
	for(int i=1;i<D.size()-1;i++){
		b=b*10+D[i]-'0';
	}
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	char aa=B[B.size()-1],bb=D[D.size()-1];
	if(!(((aa>='A'&&aa<='C')&&(bb>='A'&&bb<='C'))||(aa>='D'&&aa<='F')&&(bb>='D'&&bb<='F'))){
		cout<<"1100";
		return 0;
	}
	if(char(aa+1)==bb||char(aa-1)==bb){
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}

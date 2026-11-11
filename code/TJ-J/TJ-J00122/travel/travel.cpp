#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string x;
	string y;
	int x1;
	int y1;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	for(char c:s1){
		if(c>='0'&&c<='9'){
			x+=c;
		}
	}
	for(char c:s2){
		if(c>='0'&&c<='9'){
			y+=c;
		}
	}
	if(x==y&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	for(char c:s1){
		if((c>='A'&&c<='E')){
			x1+=c;
			break;
		}
	}
	for(char c:s2){
		if((c>='A'&&c<='E')){
			y1+=c;
			break;
		}
	}
	if((((x1>='A'&&x1<='C')&&(y1>='A'&&y1<='C'))||((x1>='D'&&x1<='E')&&(y1>='D'&&y1<='E')))&&x==y&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(((x1-y1==1&&x1!=68)||(x1-y1==-1&&y1!=68))&&c1==c2&&x==y){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

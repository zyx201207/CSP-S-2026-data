#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a="",b="";
	char x,y;
	for(int i=1;i<=3;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a+=s1[i];
		}
		if(s1[i]>='A'&&s1[i]<='Z'){
			x=s1[i];
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			b+=s2[i];
		}
		if(s2[i]>='A'&&s2[i]<='Z'){
			y=s2[i];
		}
	}
	if(c1==c2&&c1!="01"&&c1!="16"){
		if(a==b){
			if((x>='D'&&y>='D')||(x<='C'&&y<='C')){
				if(x-y==1||y-x==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

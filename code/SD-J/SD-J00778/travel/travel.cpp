#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2,x1,x2;
	cin>>c1>>s1>>c2>>s2;
	string a;
	if(c1==c2){
		a="1";
		x1=s1[0]+s1[1];
		x2=s2[0]+s2[1];
		if(x1==x2){
			a+="1";
			x1=s1[2];
			x2=s2[2];
			if((x1<="C" &&x2<="C")||(x1>"C" && x2>"C")){
				a+="1";
				if(x1>"C" && x2>"C"){
					a+="1"; 
				}else if(x1<="C" &&x2<="C"){
					if((x1=="A"&&x2=="B")||(x1=="B" &&x2=="A")){
						a+="1";
					}else if((x1=="C"&&x2=="B")||(x1=="B" &&x2=="C")){
						a+="1";
					}else{
						a+="0";
					}
				}else{
					a+="0";
				}
			}else{
				a="1100";
			}
		}else{
			a="1000";
		}
	}else{
		a="0000";
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

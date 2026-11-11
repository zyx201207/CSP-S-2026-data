#include<iostream>
using namespace std;
int bianhao1,bianhao2;
string zuohao1,zuohao2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>bianhao1>>zuohao1>>bianhao2>>zuohao2;
	
	if(int(bianhao1)==int(bianhao2)){
		if(zuohao1[1]==zuohao2[1] &&zuohao1[0]==zuohao2[0]){
			if(zuohao1<="C"&&zuohao2<="C"||zuohao1>"C"&&zuohao2>"C"){
				if(zuohao1[2]+1==zuohao2[2]||zuohao2[2]+1==zuohao1[2]){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
		cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}


} 

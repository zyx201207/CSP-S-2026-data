#include<iostream>
#include<string>
using namespace std;
string xiang1,xiang2,zuo1,zuo2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>xiang1>>zuo1>>xiang2>>zuo2;
	if(xiang1==xiang2){
		cout<<"1";
		int l1=zuo1.size(),l2=zuo2.size();
		if(zuo1[0]==zuo2[0]&&zuo1[1]==zuo2[1]){
			cout<<"1";
			if(((zuo1[2]>='A')&&(zuo1[2]<='C')&&(zuo2[2]>='A')&&(zuo2[2]<='C'))||((zuo1[2]>='D')&&(zuo1[2]<='E')&&(zuo2[2]>='D')&&(zuo2[2]<='E'))){
				cout<<"1";
				if(zuo1[2]+1==zuo2[2]||zuo1[2]-1==zuo2[2]){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 

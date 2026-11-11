#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","travle.in",stdin);
	freopen("w","travle.out",stdout);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int pai1=(s1[0]-'0')*10+(s1[1]-'0');
		int pai2=(s2[0]-'0')*10+(s2[1]-'0');
		if(pai1==pai2){
			cout<<"1";
			char lie1=s1[2];
			char lie2=s2[2];
			if((lie1<='C'&&lie2<='C')||(lie1>='c'&&lie2>='c')){
				cout<<"1";
				if(abs((int)(lie1-lie2))==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

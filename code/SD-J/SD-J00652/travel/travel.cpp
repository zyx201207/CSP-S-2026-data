#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
	}else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char z1=s1[2],z2=s2[2];
			if(z1=='A'&&z2=='B'){
				cout<<"11";
			}else if(z1=='A'&&z2=='C'){
				cout<<"10";
			}else if(z1=='A'){
				cout<<"00";
			}else if(z1=='B'&&z2=='A'){
				cout<<"11";
			}else if(z1=='B'&&z2=='C'){
				cout<<"11";
			}else if(z1=='B'){
				cout<<"00";
			}else if(z1=='C'&&z2=='A'){
				cout<<"10";
			}else if(z1=='C'&&z2=='B'){
				cout<<"11"; 
			}else if(z1=='C'){
				cout<<"00";
			}else if(z1=='D'&&z2=='F'){
				cout<<"11";
			}else if(z1=='D'){
				cout<<"00";
			}else if(z1=='F'&&z2=='D'){
				cout<<"11";
			}else if(z1=='F'){
				cout<<"00";
			}
		}else{
			cout<<"000"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

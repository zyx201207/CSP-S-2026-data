#include<iostream> 
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1>>s1>>c2>>s2;
	bool cbol,sbol;
	for(int i = 1;i<=1;i++) {
		if(c1==c2)
		{
			cout<<1;
		}
		else{
			cout<<0000;
		}
		if(s2[0]==c2[0]||s2[1]==c2[1])
		{
			cout<<1;
		}
		else{
			cout<<000;
		}
		if(s2[2]=='A'||s2[2]=='B'||s2[3]=='C'){
			sbol = 1;
		}
		else{
			sbol = 0;
		}
		if(c2[2]=='A'||c2[2]=='B'||c2[3]=='C'){
			cbol = 1;
		}
		else{
			cbol = 0;
		}
		if(cbol==sbol){
			cout<<1;
		}
		else{
			cout<<00;
		}
		if((int(c2[2])-int(s2[2]) == 1||int(s2[2])-int(c2[2]) == 1)&&(c2[2] !='C'&&s2[2]!='D')||(c2[2] !='D'&&s2[2]!='C')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}

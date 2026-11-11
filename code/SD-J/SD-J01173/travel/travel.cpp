#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s11,s12,s13,s21,s22,s23;
	cin>>c1;
	s11=getchar();s11=getchar();s12=getchar();s13=getchar();
	cin>>c2;
	s21=getchar();s21=getchar();s22=getchar();s23=getchar();
	if(c1==c2){
		if(s11=s21&&s12==s22){
			if((s13=='A'||s13=='B'||s13=='C')&&(s23=='A'||s23=='B'||s23=='C')){
				if(s13+1==s23||s13-1==s23){
					cout<<"1111"<<'\n';
				}
				else{
					cout<<"1110"<<'\n';
				}
			}
			else if(((s13=='C'||s13=='D')&&(s23=='C'||s23=='D'))){
				if(s13+1==s23||s13-1==s23){
					cout<<"1111"<<'\n';
				}
				else{
					cout<<"1110"<<'\n';
				}
			}
			else{
				cout<<"1100"<<'\n';
			}
		}
		else{
			cout<<"1000"<<'\n';
		}
		
	}
	else{
		cout<<"0000"<<'\n';
	}
	return 0;
}


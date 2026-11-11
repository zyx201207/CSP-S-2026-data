#include<bits/stdc++.h>
using namespace std;
string aa,ab,ba,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>ab>>ba>>bb;
	if(aa==ba){
		cout<<"1";
		if(ab[0]==bb[0]&&ab[1]==bb[1]){
			cout<<"1";
			if((ab[2]>='A'&&ab[2]<='C'&&bb[2]>='A'&&bb[2]<='C')||(ab[2]>='D'&&ab[2]<='F'&&bb[2]>='D'&&bb[2]<='F')){
				cout<<1;
				if((ab[2]=='A'&&bb[2]=='B')||(ab[2]=='B'&&bb[2]=='A')||(ab[2]=='B'&&bb[2]=='C')||(ab[2]=='C'&&bb[2]=='B')||(ab[2]=='D'&&bb[2]=='F')||(ab[2]=='F'&&bb[2]=='D')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


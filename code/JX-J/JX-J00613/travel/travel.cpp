#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	int e=a1[0]*10+a1[1],f=a1[0]*10+b1[1];
	if(a==b){
		 cout<<"1";
		if(e==f){
			cout<<"1";
			if(((int)a1[2]-'A'<=2&&(int)b1[2]-'A'<=2)||((int)a1[2]-'A'>2&&(int)b1[2]-'A'>2)){
				cout<<"1";
				char c=a1[2],d=b1[2];
				if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||(c=='D'&&d=='E')||(c=='E'&&d=='D')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

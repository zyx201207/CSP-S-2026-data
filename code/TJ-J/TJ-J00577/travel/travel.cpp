#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if((b[0]==d[0])&&(b[1]==d[1])){
			cout<<1;
			char e=b[2];
			char f=d[2];
			char A='A';
			char B='B';
			char C='C';
			char D='D';
			char F='F';
			if( ( ((e==A)||(e==B)||(e==C)) && ( (f==D)||(f==F) ))
			||( ((f==A)||(f==B)||(f==C)) && ( (e==D)||(e==F) ))){
				cout<<"00";
			}else {
				cout<<1;
				if(abs(e-f)==1){
					cout<<1;
				}else cout<<0;
			}
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

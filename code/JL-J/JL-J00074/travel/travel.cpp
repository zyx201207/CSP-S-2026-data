#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<"1";
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<'1';
			int x=c[2]-'A',y=d[2]-'A';
			if((x<=2&&y<=2)||((x==5&&y==3)||(x==3&&y==5))){
				cout<<'1';
				if((abs(x-y)==1)||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
					cout<<'1';
				}
				else cout<<"0\n";
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}

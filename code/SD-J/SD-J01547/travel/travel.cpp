#include<bits/stdc++.h>
using namespace std;	
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=(c1[0]-'0')*10+(c1[1]-'0');
	int y=(s1[0]-'0')*10+(s1[1]-'0');
	char z=s1[2];
	int x1=(c2[0]-'0')*10+(c2[1]-'0');
	int y1=(s2[0]-'0')*10+(s2[1]-'0');
	char z1=s2[2];
	if(x1==x){
		cout<<1;
		if(y==y1){
			cout<<1;
			if((z<='C'&&z1<='C')||(z>='D'&&z1>='D')){
				cout<<1;
				if(z+1==z1||z1+1==z){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

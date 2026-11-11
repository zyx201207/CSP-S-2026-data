#include<bits/stdc++.h>
using namespace std;
int a,b,e,f;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		e=(c[0]-'0')*10+(c[1]-'0');
		f=(d[0]-'0')*10+(d[1]-'0');
		if(e==f){
			cout<<1;
			int g=(c[2]-'A'+1),
			h=(d[2]-'A'+1);
			if(((h<=3)&&(g<=3))||((h>3)&&(g>3))){
				cout<<1;
				if(abs(g-h)==1){
					cout<<1;
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

#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int r=s1[2]-'A'+1,x=s2[2]-'A'+1;
	if(r>=4&&x>=4){
		cout<<"1";
		if(r!=x){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(r<=3&&x<=3){
		cout<<"1";
		if(abs(r-x)==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"00";
	}
	return 0;
}

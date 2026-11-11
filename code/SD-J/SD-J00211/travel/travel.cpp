#include<bits/stdc++.h>
using namespace std;
string cR,cX,sR,sX;
int lR,lX;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	if(cR==cX){
		cout<<"1";
		lR=(sR[0]-'0')*10+sR[1]-'0';
		lX=(sX[0]-'0')*10+sX[1]-'0';
		if(lR==lX){
			cout<<"1";
			if(sR[2]<='C'&&sX[2]<='C'||sR[2]>='D'&&sX[2]>='D'){
				cout<<"1";
				if(sR[2]>sX[2])swap(sR,sX);
				if(sX[2]=='F')sX[2]--;
				cout<<((sX[2]-sR[2])==1);
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


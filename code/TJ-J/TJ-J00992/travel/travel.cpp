#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char a,b,z,x,y,z1;
bool t=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>b>>z>>c2>>x>>y>>z1;
	if(c1[1]==c2[1]){
		if(c1[2]==c2[2]){
			cout<<"1";
		}else{
			cout<<"0000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(a==x){
		if(b==y){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	if((z=='A'||z=='B'||z=='C')&&(z1=='A'||z1=='B'||z1=='C')){
		cout<<"1";
		 
	}else if((z1=='D'||z1=='F')&&(z=='D'||z=='F')){
		cout<<"1";
		cout<<"?"<<endl;
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if((z=='A'&& z1=='B')||(z=='B'&& z1=='A')||(z=='B'&& z1=='C') || (z=='C'&& z1=='B')){
		cout<<"1";
	}else if((z=='D'||z=='F')&&(z1=='D'||z1=='F')){
		cout<<"1";
	}else{
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

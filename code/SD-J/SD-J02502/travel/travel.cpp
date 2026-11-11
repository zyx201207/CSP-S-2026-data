#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=0;
	if(c1==c2&&(c1[1]!='1'&&c1!="16")){
		cout<<1;
	}else{
		cout<<"0000";
		f=1;
	}
	char a=s1[2],b=s2[2];
	string n,m;
	for(int i=0;i<2;i++){
		n=n+s1[i];
		m=m+s2[i];
	}
	if(n==m&&f==0){
		cout<<1;
		if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
			cout<<1;
			if(a-1==b||a+1==b){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
	}else if(f==0){
		cout<<"000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

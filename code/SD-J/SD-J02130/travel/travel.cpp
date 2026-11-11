#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10],b[10],c[10],d[10];
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(((b[2]-'A')/3)==((d[2]-'A')/3)){
				cout<<"1";
				if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){
					cout<<"0";
				}else{
					cout<<"1";
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

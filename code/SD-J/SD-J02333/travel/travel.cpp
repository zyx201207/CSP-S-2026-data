#include<bits/stdc++.h>
using namespace std;int c,p,c0,p0;char z,z0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%02d %02d%c %02d %02d%c",&c,&p,&z,&c0,&p0,&z0);
	if(c!=c0){
		cout<<"0000";
	}else{
		cout<<"1";
		if(p!=p0){
			cout<<"000";
		}else{
			cout<<"1";
			if(!(z=='A'&&z0=='B'||z0=='A'&&z=='B'||z=='A'&&z0=='C'||z0=='A'&&z=='C'||z=='C'&&z0=='B'||z0=='C'&&z=='B'||z=='D'&&z0=='F'||z=='F'&&z0=='D')){
				cout<<"00";
			}else{
				cout<<"1";
				if(!(z=='A'&&z0=='B'||z0=='A'&&z=='B'||z=='C'&&z0=='B'||z0=='C'&&z=='B'||z=='D'&&z0=='F'||z=='F'&&z0=='D')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

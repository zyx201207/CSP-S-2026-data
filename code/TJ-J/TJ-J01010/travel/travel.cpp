#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char a[3];
char b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	int d,e,f;
	char n[3]={'A','B','C'};
	char m[2]={'D','F'};
	if(c1!=c2){
		cout<<0<<' '<<0<<' '<<0<<' '<<0;
	}else{
		if(a[0]==b[0]&&a[1]==b[1]){
			d=1;
			if(a[2]=='A'&&b[2]=='B'){
				e=1;
				f=1;
			} else if(a[2]=='B'&&b[2]=='A'){
				e=1;
				f=1;
			}else if(a[2]=='A'&&b[2]=='C'){
				e=1;
				f=0;
			}else if(a[2]=='C'&&b[2]=='A'){
				e=1;
				f=0;
			}else if(a[2]=='B'&&b[2]=='C'){
				e=1;
				f=1;
			}else if(a[2]=='C'&&b[2]=='B'){
				e=1;
				f=0;
			}else if(a[2]=='D'&&b[2]=='F'){
				e=1;
				f=1;
			}else if(a[2]=='F'&&b[2]=='D'){
				e=1;
				f=1;
			}else{
				e=0;
				f=0;
			}
		cout<<1<<' '<<d<<' '<<e<<' '<<f;
		}	else{
			cout<<1<<' '<<0<<' '<<0<<' '<<0;
		}
	}
	return 0;
} 

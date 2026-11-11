#include<bits/stdc++.h>
using namespace std;
int c1,r1,c3;
string  c2,r2;
bool f1,f2;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>c1>>c2>>r1>>r2;
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
		f1=1;
	}
	else{
		f1=0;
	}
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
		f2=1;
	}
	else{
		f2=0;
	}
	if(c1==r1){
		if(c2[0]=r2[0]&&c2[1]==r2[1]){
			if(f2==f1){
				if(c2[2]=='B'&&r2[2]=='A'||c2[3]=='B'&&r2[3]=='A'||c2[3]=='C'&&r2[3]=='B'||c2[3]=='B'&&r2[3]=='C'||c2[3]=='D'&&r2[3]=='F'||c2[3]=='F'&&r2[3]=='D'){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	//cout<<c1<<" "<<c2;
	fclose (stdin);
	fclose (stdout);
	return 0;
	
}

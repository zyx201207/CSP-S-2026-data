#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int num,cnt,se1,se2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	num=a[0]*10+a[1];
	cnt=c[0]*10+c[1];
	if(num==cnt){
		cout<<'1';
		se1=b[0]*10+b[1];
		se2=d[0]*10+d[1];
		if(se1==se2){
			cout<<'1';
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					cout<<'1';
					int x,y;
					x=(int)b[2];
					y=(int)d[2];
					if(abs(x-y)==1){
						cout<<'1';
					}
					else{
						cout<<'0';
					}
				}
				else{
					cout<<'0'<<'0';
				}
			}
			else{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					cout<<'0'<<'0';
				}
				else{
					cout<<'1'<<'1';
				}
			}
		}
		else{
			cout<<'0'<<'0'<<'0';
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
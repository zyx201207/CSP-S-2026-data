#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int x1=(s1[0]-48)*10+s1[1]-48,x2=(s3[0]-48)*10+s3[1]-48,y1=(s2[0]-48)*10+s2[1]-48,y2=(s4[0]-48)*10+s4[1]-48;
//	cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' '<<endl;
	if(x1==x2){
		if(y1==y2){
			if(s2[2]/'D'==s4[2]/'D'){
				if(s2[2]/'D'==1){
					cout<<1111<<endl;
				}
				else if(s2[2]+1==s4[2]||s2[2]-1==s4[2]){
					cout<<1111<<endl;
				}
				else{
					cout<<1110<<endl;
				}
			}
			else{
				cout<<1100<<endl;
			}
		}
		else{
			cout<<1000<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
} 


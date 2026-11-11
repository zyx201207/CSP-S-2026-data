#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
string s1,s2,c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string x=s1.substr(0,2);
		string y=s2.substr(0,2);
		if(x==y){
			cout<<1;
			x=s1.substr(2,1);
			y=s2.substr(2,1);
			int flag=0;
			if("A"<=x&&x<="C"&&"A"<=y&&y<="C"){
				cout<<1;
				flag=1;
			}else if("D"<=x&&x<="E"&&"D"<=y&&y<="E"){
				cout<<1;
				flag=2;
			}
			if(flag==1){
				if((x=="A"&&y=="B")||(x=="B"&&y=="C")||(x=="B"&&y=="A")||(x=="C"&&y=="B")){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(flag==2){
				cout<<1;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

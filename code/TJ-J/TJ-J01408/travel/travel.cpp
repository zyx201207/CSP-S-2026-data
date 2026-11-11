#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string c1,string c2){
	int tmp1=0,tmp2=0;
	for(int i=0;i<2;i++){
		tmp1+=c1[i]-'0';
		tmp2+=c2[i]-'0';
		tmp1*=10;
		tmp2*=10;
	}
	if(tmp1==tmp2)return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(check(c1,c2)){
		cout<<"1";
		if(check(s1,s2)){
			cout<<"1";
			int t1=s1[2]-'A',t2=s2[2]-'A';
			if(t1<=2&&t2<=2){
				cout<<"1";
				if(abs(t1-t2)==1)cout<<"1";
				else cout<<"0";
			}else if(t1>2&&t2>2){
				cout<<"1";
				if(abs(t1-t2)==2)cout<<"1";
				else cout<<"0";
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

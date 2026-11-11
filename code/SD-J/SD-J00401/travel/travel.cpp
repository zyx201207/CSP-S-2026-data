#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1,c2,a,b,a1,b1;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	
	if(s1[2]>='A'&&s1[2]<='C'){
		a1=s1[2]-'A'+1;
	}else if(s1[2]=='D'){
		a1=5;
	}else{
		a1=6;
	}
	
	if(s2[2]>='A'&&s2[2]<='C'){
		b1=s2[2]-'A'+1;
	}else if(s2[2]=='D'){
		b1=5;
	}else{
		b1=6;
	}
	
	//cout<<a<<" "<<b<<" "<<a1<<" "<<b1<<endl;
	
	if(c1==c2){
		cout<<1;
		if(a==b){
			cout<<1;
			if((a1>=1&&a1<=3&&b1>=1&&b1<=3)||(a1>=5&&b1>=5)){
				cout<<1;
				if(a1-b1==1||a1-b1==-1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	
	return 0;
}

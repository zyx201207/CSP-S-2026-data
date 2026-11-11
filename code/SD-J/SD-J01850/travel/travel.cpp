#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int num,num1;
char s,s1;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    for(int i=0;i<=1;i++){
		num=num*10+(b[i]-'0');
		num1=num1*10+(b1[i]-'0');
	}
	s=b[2];
	s1=b1[2];
    if(a==a1){
    	cout<<"1";
    	if(num==num1){
    		cout<<1;
    		if((s=='C'&&s1=='D')||(s=='D'&&s1=='C')){
    			cout<<"00";
			}
			else if((s<='C'&&s>='A'&&s1<='C'&&s1>='A')||(s<='F'&&s>='D'&&s1<='F'&&s1>='D')){
				cout<<"1";
				if((int)(abs(s-s1))==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
    return 0;
}


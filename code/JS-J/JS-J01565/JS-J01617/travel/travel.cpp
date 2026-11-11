#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		int num1=0,num2=0,st1=0,st2=0;
		st1=b[b.size()-1]-'A';
		st2=d[d.size()-1]-'A';
		for(int i=0;i<(int)b.size();i++){
			if(isdigit(b[i])){
				while(isdigit(b[i])){
					num1=num1*10+b[i]-'0';
					i++;
				}
			}
			else break;
		}
		for(int i=0;i<(int)d.size();i++){
			if(isdigit(d[i])){
				while(isdigit(d[i])){
					num2=num2*10+d[i]-'0';
					i++;
				}
			}
			else break;
		}
		if(num1==num2){
			cout<<1;
			if((st1<=2 && st2<=2) || (st1>2 && st2>2)){
				cout<<1;
				if(abs(st1-st2)==1 && !((st1==2 && st2==3) || (st2==3 && st1==2))) cout<<1;
				else cout<<0;
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

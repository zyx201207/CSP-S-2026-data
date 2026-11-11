#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
	}else{
        cout<<"0000";
        return 0;
    }
	int row1=(s1[0]-'0')*10+(s1[1]-'0');
	int row2=(s2[0]-'0')*10+(s2[1]-'0');
    bool flag=true;
	if(row1==row2) cout<<1;
	else{
        flag=false;
        cout<<0;
    }
	char let1=s1[2],let2=s2[2];

	if(flag==1 && ((let1=='A'||let1=='B'||let1=='C') && (let2=='A'||let2=='B'||let2=='C')) || ((let1=='D'||let1=='E') && (let2=='D'||let2=='E'))){
		cout<<1;
	}else{
        cout<<0;
        flag=0;
    }
    
	int bar1=s1[2],bar2=s2[2];
	
	if((let1=='C'&&let2=='D') || (let1=='D'&&let2=='C')){
		cout<<0;
		return 0;
	}
	
	if(abs(bar1-bar2)==1 && flag) cout<<1;
	else cout<<0;
	return 0;
}

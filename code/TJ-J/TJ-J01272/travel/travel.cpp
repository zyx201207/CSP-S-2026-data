#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(a1[0]==b1[0]){
		if(a1[1]==b1[1]){
			cout<<1;
			if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C'&&b1[2]=='A'||b1[2]=='B'||b1[2]=='C')||(a1[2]=='D'||a1[2]=='F'&&b1[2]=='D'||b1[2]=='F')) cout<<1;
			else{
				cout<<"00";
				return 0;
			}
			if((a1[2]==b1[2]+1||a1[2]==b1[2]-1)&&a1[2]!='C'&&a1[2]!='D'&&b1[2]!='C'&&b1[2]!='D') cout<<1;
			else cout<<0;
		}
		else{
			cout<<"000";
			return 0;	
		}
	}else{
		cout<<"000";
		return 0;	
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}


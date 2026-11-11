#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int p=s1[2]-'A'+1,q=s2[2]-'A'+1;
	if((p<=3&&q<=3)||(p>3&&q>3)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(p<=3){
		if(p+1==q||p-1==q){
			cout<<1;
		}
		else cout<<"0";
	}
	else if(p>3){
		if(p+2==q||p-2==q){
			cout<<1;
		}
		else cout<<"0";
	}
	return 0;
}

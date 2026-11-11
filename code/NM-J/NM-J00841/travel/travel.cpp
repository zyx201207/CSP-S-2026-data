#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char a_1,a_2,q,b_1,b_2,w;
	
	cin>>a>>a_1>>a_2>>q>>b>>b_1>>b_2>>w;
	
	int c=(a_1-'0')*10+(a_2-'0');
	int d=(b_1-'0')*10+(b_2-'0');
	
	if(a==b)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	
	if(c==d)cout<<1;
	else cout<<0;
	
	if( ((q=='A'||q=='B'||q=='C')&&(w=='A'||w=='B'||w=='C'))||((q=='D'||q=='F')&&(w=='D'||w=='F')) ){
		cout<<1;
		if(abs(q-w)==1){
			cout<<1;
			return 0;
		}
	}else{
		cout<<0;
	}
	cout<<0;
	return 0;
}

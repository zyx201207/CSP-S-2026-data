#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c;
	int s1,c1;
	cin>>c1>>c>>s1>>s;
	if(c1==s1){
		cout<<1;
		int t=0;
		for(int i=0;i<2;i++){
		if(c[i]==s[i]){
			t++;
		}
	}
		if(t==2){
		cout<<1;
		for(int i=2;i<3;i++){
			a=s[i]-'A';
			b=c[i]-'A';
			if((a<3&&b<3)||(b>3&&a>3)){
				cout<<1;
			int x=abs(a-b);
			if(x==1){
				cout<<1;
			}else{
				cout<<0;
			}
			}else{
				cout<<"00";
			}
			
		}
	}else{
		cout<<"000";
	}
	}else{
		cout<<"0000";
	}
//	cout<<endl;
//	cout<<a<<" "<<b<<endl;  
	return 0;
} 

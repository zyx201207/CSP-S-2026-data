#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b1,b2;
};
node x,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>r.a>>s1>>x.a>>s2;
	r.b1=0;
	x.b1=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			r.b1*=10;
			r.b1+=s1[i]-'0';
		}
		else{
			r.b2=s1[i]-'A'+1;
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			x.b1*=10;
			x.b1+=s2[i]-'0';
		}
		else{
			x.b2=s2[i]-'A'+1;
		}
	}
	if(r.a==x.a){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(r.b1==x.b1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(r.b2==1||r.b2==2||r.b2==3){
		if(x.b2==1||x.b2==2||x.b2==3){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		if(x.b2==4||x.b2==5){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(abs(r.b2-x.b2)==1&&!(r.b2==3&&x.b2==4||r.b2==4&&x.b2==3)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
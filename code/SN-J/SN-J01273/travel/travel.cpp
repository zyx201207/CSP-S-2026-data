#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string s="",c=""; 
	for(int i=0;i<2;i++){
		s+=s2[i];
		c+=c2[i];
	}
	if(s==c&&s1==c1){
		cout<<1;
		if((s2[2]=='A'&&c2[2]=='B')||(s2[2]=='A'&&c2[2]=='C')){
			cout<<1;
			if(s2[2]=='A'&&c2[2]=='B'){
				cout<<1;
			}
			else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
				cout<<1;
			}
			else if(s2[2]=='C'&&c2[2]=='B'){
				cout<<1;
			}
			else if(s2[2]=='D'&&c2[2]=='F'){
				cout<<1;
			}
			else if(s2[2]=='F'&&c2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
			cout<<1;
			if(s2[2]=='A'&&c2[2]=='B'){
				cout<<1;
			}
			else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
				cout<<1;
			}
			else if(s2[2]=='C'&&c2[2]=='B'){
				cout<<1;
			}
			else if(s2[2]=='D'&&c2[2]=='F'){
				cout<<1;
			}
			else if(s2[2]=='F'&&c2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if((s2[2]=='C'&&c2[2]=='B')||(s2[2]=='C'&&c2[2]=='A')){
			cout<<1;
			if(s2[2]=='A'&&c2[2]=='B'){
				cout<<1;
			}
			else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
				cout<<1;
			}
			else if(s2[2]=='C'&&c2[2]=='B'){
				cout<<1;
			}
			else if(s2[2]=='D'&&c2[2]=='F'){
				cout<<1;
			}
			else if(s2[2]=='F'&&c2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if(s2[2]=='D'&&c2[2]=='F'){
			cout<<1;
			if(s2[2]=='A'&&c2[2]=='B'){
				cout<<1;
			}
			else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
				cout<<1;
			}
			else if(s2[2]=='C'&&c2[2]=='B'){
				cout<<1;
			}
			else if(s2[2]=='D'&&c2[2]=='F'){
				cout<<1;
			}
			else if(s2[2]=='F'&&c2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if(s2[2]=='F'&&c2[2]=='D'){
			cout<<1;
			if(s2[2]=='A'&&c2[2]=='B'){
				cout<<1;
			}
			else if((s2[2]=='B'&&c2[2]=='A')||(s2[2]=='B'&&c2[2]=='C')){
				cout<<1;
			}
			else if(s2[2]=='C'&&c2[2]=='B'){
				cout<<1;
			}
			else if(s2[2]=='D'&&c2[2]=='F'){
				cout<<1;
			}
			else if(s2[2]=='F'&&c2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"000"; 
		return 0;
	}
	return 0;
}

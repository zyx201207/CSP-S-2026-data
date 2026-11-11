#include<bits/stdc++.h>
using namespace std;
long long a,b,cnt1,cnt2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	for(int i=0;i<2;i++){
		cnt1=cnt1*10+(int(s1[i])-48);
		cnt2=cnt2*10+(int(s2[i])-48);
	}
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(cnt1==cnt2){
			cout<<1;
			if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
				cout<<1;
				if(s2[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s2[2]=='A'&&(s1[2]=='B'||s1[2]=='C')){
				cout<<1;
				if(s1[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s2[2]=='B'&&(s1[2]=='A'||s1[2]=='C')){
				cout<<11;
			}else if(s2[2]=='C'&&(s1[2]=='B'||s1[2]=='A')){
				cout<<1;
				if(s1[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<11;
			}else if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A')){
				cout<<1;
				if(s2[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(s1[2]=='F'&&s2[2]=='D'){
				cout<<11;
			}else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<11;
			}else if(s2[2]=='F'&&s1[2]=='D'){
				cout<<11;
			}else if(s2[2]=='D'&&s1[2]=='F'){
				cout<<11;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}

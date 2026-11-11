#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll n,m;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m){
		size_t i;
		for(i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				break;
			}
		}
		bool f=false;
		if(i==s1.size()-1){
			if(s1[2]==s2[2]+1||s2[2]==s1[2]+1){
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					f=true;
				}else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='C')){
					f=true;
				}else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')){
					f=true;
				}else{
					cout<<1100<<endl;
					return 0;
				}
				if(f){
					if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
						cout<<1111<<endl;
						return 0;
					}else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
						cout<<1111<<endl;
						return 0;
					}else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
						cout<<1111<<endl;
						return 0;
					}else{
						cout<<1110<<endl;
						return 0;
					}
				}
			}else{
				cout<<1110<<endl;
			}
		}else{
			cout<<1000<<endl;
		}
	}else{
		cout<<"0000\n";
	}
	return 0;
}

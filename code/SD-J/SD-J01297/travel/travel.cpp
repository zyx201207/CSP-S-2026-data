#include<bits/stdc++.h>
using namespace std;
long long a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s[15];
	for(long long i=1;i<=4;i++){
		if(i==2 || i==4){
			cin>>a[i];
		}	
		cin>>s[i];
	}
	if(s[1]==s[3]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a[2]==a[4]){
		cout<<1;
		if((s[2]=="A" && s[4]=="B") || (s[2]=="B" && s[4]=="A")){
			cout<<1;
			cout<<1;
		}else if((s[2]=="D" && s[4]=="F") || (s[2]=="F" && s[4]=="D")){
			cout<<1;
			cout<<1;
		}else if((s[2]=="B" && s[4]=="C") || (s[2]=="C" && s[4]=="B")){
			cout<<1; 
			cout<<1;
		}else{
			if((s[2]=="A" && s[4]=="C") || (s[2]=="C" && s[4]=="A")){
				cout<<1;
			}else{
				cout<<0;
			}
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}

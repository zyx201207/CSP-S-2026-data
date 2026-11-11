#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,f=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]) f+=1;
    }
    if(f==2) cout<<1;
    else{
    	cout<<0<<0<<0;
    	return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
		if(s1[2]=='B'||s2[2]=='B'){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}	
	}
	else if(s1[2]>='D'&&s2[2]>='D'){
		cout<<1<<1;
		return 0;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	return 0;
}

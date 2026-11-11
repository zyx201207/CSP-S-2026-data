#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	char c=a[0];
	char d=a[1];
	char e=b[0];
	char f=b[1];
	if((e-'0')*10+f-'0'!=(c-'0')*10+d-'0'){
		cout<<"000";
		return 0;
	}
	cout<<1;
	c=a[2];
	d=b[2];
	if(a[2]=='A'){
		if(d=='B'){
			cout<<"11";
		}
		if(d=='C'){
			cout<<"10";
		}
	}
	if(c=='C'){
		if(d=='B'){
			cout<<"11";
		}
		if(d=='A'){
			cout<<"10";
		}
		else{
			cout<<"00";
		}
	}
	if(c=='B'){
		if(d=='A'){
			cout<<"11";
		}
		if(d=='C'){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	if(c=='D'){
		if(d=='F'){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	if(c=='F'){
		if(d=='D'){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	
	return 0;
}

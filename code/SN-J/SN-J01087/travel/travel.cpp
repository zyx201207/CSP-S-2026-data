#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		string e=c.substr(0,c.length()-1);
		string f=d.substr(0,d.length()-1);
		if(e!=f)cout<<"000";
		else{
			cout<<100;
		}
	}else{cout<<"0000";
	}
}

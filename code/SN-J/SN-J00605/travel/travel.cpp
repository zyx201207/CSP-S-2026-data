#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=b){
		cout<<1;
	}else{
	    cout<<0;
	}		
    if(c!=d){
    	cout<<1;
    }else{
    	cout<<0;
	}
	if(a==c){
		cout<<1;
	}else{
	    cout<<0;
	}		
    if(b==d){
    	cout<<1;
    }else{
    	cout<<0;
	}
	return 0;
}

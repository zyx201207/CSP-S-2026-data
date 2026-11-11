#include<bits/stdc++.h>
using namespace std;
string  s,t;
int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int n,m,k,l;
    int z=65,x=67,c=68,v=69;//,b,o;
    
    cin>>n>>s>>m>>t;
    k=s.size();
    l=t.size();
    if(n==m){
		cout<<1;
	}
	else{cout<<0;}
    for(int i=2;i<=k;i++){
		for(int j=2;j<l;j++){
		if(j==2&&s[i]==t[j]&&s[i-1]==t[j-1]){
			cout<<1;
		}
		else{
		    cout<<0;	
		}
		}
		//
		if(i==3){
		if(s[i]>=z&&s[i]<=x&&t[i]>=z&&t[i]<=x){
		  cout<<1;
		}
	    else if(s[i]>=c&&s[i]<=v&&t[i]>=c&&t[i]<=v){
			cout<<1;
		}
		else{cout<<0;}
		//
		if(s[i]-t[i]==1){
		  cout<<1;return 0;	
		}
		else{cout<<0;return 0;}
		}
	}
    return 0;
}

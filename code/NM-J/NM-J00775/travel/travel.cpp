#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,m,a,b;
    char a1,a2;
    cin>>n>>a>>a1>>m>>b>>a2;
    if(m==n){
        cout<<1;
        if(a==b){
        	cout<<1;
	        if(a1>='A'&&a1<='C'&&a2>='A'&&a2<='C'||a1>='D'&&a1<='F'&&a2>='D'&&a2<='F'){
	            cout<<1;
	            if(a1+1==a2||a1-1==a2){
	                cout<<1;
	            }else{
	                cout<<0;
	            }
	        }else{
	            cout<<0<<0;
        	}
		

	    }else{
	        cout<<0<<0<<0;
	    }
	}else{
		cout<<0<<0<<0<<0;
	}
    return 0;
}
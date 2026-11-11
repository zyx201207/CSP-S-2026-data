#include<bits/stdc++.h>
using namespace std;
int absi(int a){if(a<0) return -a;return a;}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,ac,b,bc;
    char as,bs;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    ac=(s1[0]-'0')*10+s1[1]-'0';
    bc=(s2[0]-'0')*10+s2[1]-'0';
    as=s1[2];
    bs=s2[2];
    if(a==b){
    	cout<<1;
    	if(ac==bc){
    	    cout<<1;
    	    if((as<='C' && bs<='C') or (as>='D' && bs>='D')){
    	    	cout<<1;
    	    	if(abs(as-bs)==1) cout<<1;
    	    	else cout<<0;
    	    }
    	    else cout<<"00";
    	}
    	else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}

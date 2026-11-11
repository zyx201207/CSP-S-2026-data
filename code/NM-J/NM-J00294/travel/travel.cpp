#include<bits/stdc++.h>
using namespace std;
int f(char c){
	if(c=='A'||c=='B'||c=='C') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
    string a,b,c,d;
    int ansa=0,ansb=0;
    char ca,cb;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<'1';
    else{
    	cout<<"0000";
    	return 0;
	}
    for(int i=0;i<b.size();i++){
        if(isdigit(b[i])){
        ansa=ansa*10+b[i];
        }
        else ca=b[i];
    }
    for(int i=0;i<d.size();i++){
        if(isdigit(d[i])){
        ansb=ansb*10+d[i];
        }
        else cb=d[i];
    }
    if(ansa==ansb) cout<<'1';
    else cout<<'0';
    if(f(ca)==f(cb)&&ansa==ansb) cout<<'1';
    else cout<<'0';
    if(ca=='A'&&cb=='B'||cb=='B'&&ca=='A'||ca=='B'&&cb=='C'||ca=='C'&&cb=='B'||ca=='D'&&cb=='F'||ca=='F'&&cb=='D') cout<<'1';
    else cout<<'0';
    return 0;
}

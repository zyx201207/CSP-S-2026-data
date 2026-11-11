#include<bits/stdc++.h>
using namespace std;
int ps(char c){
    if(c=='A'||c=='B'||c=='C') return 1;
    else return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<'1';
    else{
    	cout<<"0000";
    	return 0;
	}
    int ans1=0,ans2=0;
    char c1,c2;
    for(int i=0;i<b.size();i++){
        if(isdigit(b[i])){
            ans1=ans1*10+b[i];
        }
        else c1=b[i];
    }
    for(int i=0;i<d.size();i++){
        if(isdigit(d[i])){
            ans2=ans2*10+d[i];
        }
        else c2=d[i];
    }
    if(ans1==ans2) cout<<'1';
    else cout<<'0';
    if(ps(c1)==ps(c2)&&ans1==ans2) cout<<'1';
    else cout<<'0';
    if(c1=='A'&&c2=='B'||c2=='B'&&c1=='A'||c1=='B'&&c2=='C'||c1=='C'&&c2=='B'||c1=='D'&&c2=='F'||c1=='F'&&c2=='D') cout<<'1';
    else cout<<'0';
return 0;
}

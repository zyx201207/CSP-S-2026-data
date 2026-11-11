#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool cmp(string a,string b){
    if(a.size()!=b.size()) return false;
    long long len=a.size();
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
bool change(char x){
    if(x=='A'||x=='B'||x=='C') return true;
    else return false;
}
bool pd(){
    if(abs(s1[2]-s2[2])==1){
        if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) return false;
        else return true;
    }
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(cmp(c1,c2)){
    	cout<<"1";
	    if(cmp(s1.substr(0,2),s2.substr(0,2))){
	    	cout<<"1";
		    if(change(s1[2])==change(s2[2])){
		    	cout<<"1";
			    if(pd()) cout<<"1";
			    else cout<<"0";
			}
		    else cout<<"00";
		}
	    else cout<<"000";
	}
    else cout<<"0000";
    return 0;
}

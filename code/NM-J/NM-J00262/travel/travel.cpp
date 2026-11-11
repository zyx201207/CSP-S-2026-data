#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";
    else {
		cout<<"0000";
		return 0;
		}
    int len1=s1.length(),len2=s2.length();
    if(len1!=len2){
        cout<<"000";
        return 0;
    }
    int is=1;
    for(int i=0;i<len1-1;i++){
        if(s1[i]!=s2[i]){
            is=0;
            cout<<"000";
            return 0;
        }
    }
    if(is) cout<<"1";
    char st1=s1[len1-1],st2=s2[len2-1];
    if((st1>='A'&&st1<='C'&&st2>='A'&&st2<='C')||(st1>='D'&&st1<='F'&&st2>='D'&&st2<='F')){
        cout<<"1";
    }
    else{
		cout<<"00";
		return 0;
	}
    if(abs(st1-st2)==1){
        if((st1=='C'&&st2=='D')||(st1=='D'&&st2=='C')){
            cout<<"0";
        }
        else cout<<"1";
    }
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

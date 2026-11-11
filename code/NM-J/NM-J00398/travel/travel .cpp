#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,q,w;
    char s1,s2;
    cin>>c1>>q>>s1>>c2>>w>>s2;
    if(c1==c2){
        cout<<"1";
        if(q==w){
            cout<<"1";
            if(s1=='A'&&s2=='B'||s1=='B'&&s2=='C'||s1=='A'&&s2=='C'||s1=='B'&&s2=='A'||s1=='C'&&s2=='A'||s1=='C'&&s2=='B'||s1=='D'&&s2=='F'||s1=='F'&&s2=='D'){
                cout<<"1";
                if((s1+1==s2||s1-1==s2)&&(s1!='C'&&s2!='D'||s1!='D'&&s2!='C')){
                    cout<<"1";
                }
            }
        }
    }
    if(c1!=c2){
        cout<<"0";
    }
    if(q!=w){
        cout<<"0";
    }
    if(s1!='A'&&s2!='B'||s1!='B'&&s2!='C'||s1!='A'&&s2!='C'||s1!='B'&&s2!='A'||s1!='C'&&s2!='A'||s1!='C'&&s2!='B'||s1!='D'&&s2!='F'||s1!='F'&&s2!='D'){
        cout<<"0";
    }
    if((s1+1!=s2||s1-1!=s2)&&(s1=='C'&&s2=='D'||s1=='D'&&s2=='C')){
        cout<<"0";
    }
    return 0;
}

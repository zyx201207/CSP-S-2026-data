#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0<<0<<0<<0<<endl;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<0<<0<<0<<endl;
        return 0;
    }
    if(s1[2]<='C'&&s2[2]<='C'){
        cout<<1;
        if(s1[2]=='A'&&s2[2]=='B'){
            cout<<1<<endl;
        }else if(s1[2]=='B'&&s2[2]=='C'){
            cout<<1<<endl;
        }else if(s1[2]=='B'&&s2[2]=='A'){
            cout<<1<<endl;
        }else if(s1[2]=='C'&&s2[2]=='B'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }else if(s1[2]>='D'&&s2[2]>='D'){
            cout<<1<<1<<endl;
            return 0;
    }else{
        cout<<0<<0<<endl;
    }
    return 0;
}
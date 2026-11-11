#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string s1,s2,a1,a2;
    cin>>s1>>a1>>s2>>a2;
    string b1="",b2="";
    b1=a1[0]+a1[1];
    b2=a2[0]+a2[1];
    if(s1!=s2){
        cout<<"0000"<<endl;
    }
    else if(b1!=b2){
        cout<<"1000"<<endl;
    }
    else if(a1[2]<='C'&&a2[2]>='D'){
        cout<<"1100"<<endl;
    }
    else if(a2[2]<='C'&&a1[2]>='D'){
        cout<<"1100"<<endl;
    }
    else if(a1[2]=='A'&&a2[2]=='B'){
        cout<<"1111"<<endl;
    }
    else if(a2[2]=='A'&&a1[2]=='B'){
        cout<<"1111"<<endl;
    }
    else if(a1[2]=='B'&&a2[2]=='C'){
        cout<<"1111"<<endl;
    }
    else if(a2[2]=='B'&&a1[2]=='C'){
        cout<<"1111"<<endl;
    }
    else if(a1[2]=='D'&&a2[2]=='F'){
        cout<<"1111"<<endl;
    }
    else if(a2[2]=='D'&&a1[2]=='F'){
        cout<<"1111"<<endl;
    }
    else cout<<"1110"<<endl;
    return 0;
}

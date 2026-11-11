#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b.substr(0,2)==d.substr(0,2)){
            cout<<1;
            if((b[2]<='C' && d[2]<='C')||(b[2]>='D' && d[2]>='D')){
                cout<<"1";
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"00";
        }
    }else{
        cout<<"0000";
        return 0;
    }
    int i=(b[0]-'0')*10+(b[1]-'0');
    int j=(d[0]-'0')*10+(d[1]-'0');
    int n=b[2]-'A',m=d[2]-'C';
    if(n==m && i-j<= 1 && i-j>=-1){
        cout<<"1";
    }else if(i==j && n-m<=1 && n-m>=-1){
        if(n<=2 && m<=2){
            cout<<"1";
        }else if(n>=3 && m>=3){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }
    return 0;
}

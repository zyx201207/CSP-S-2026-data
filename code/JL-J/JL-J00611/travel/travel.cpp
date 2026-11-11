#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    int m,n,x,y,p,q;
    m=b[0]-'0';
    x=b[1]-'0';
    p=b[2]-'A'+1;
    n=d[0]-'0';
    y=d[1]-'0';
    q=d[2]-'A'+1;
    if(m==n&&x==y){
        cout<<1;
        if(((p==1||p==2||p==3)&&(q==1||q==2||q==3))||((p==4||p==5)&&(q==4&&q==5))){
            cout<<1;
            if(p-q==1||p-q==-1){
                cout<<1;
            }
            else{
                cout<<0;
                return 0;
            }
        }
        else{
            cout<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}

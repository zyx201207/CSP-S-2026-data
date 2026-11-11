#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        string x=b.substr(0,2);
        string y=d.substr(0,2);
        if(x!=y){
            cout<<"000";
            return 0;
        }
        else{
            cout<<1;
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                    cout<<1;
                    if(b[2]=='A'){
                        if(d[2]=='B'){
                        cout<<1;}
                        else cout<<0;
                    }
                    else if(b[2]=='B'){
                        if(d[2]=='A'||d[2]=='C'){
                        cout<<1;}
                        else cout<<0;
                    }
                    else{
                        if(d[2]=='B'){
                        cout<<1;}
                        else cout<<0;
                    }
                }
                else{
                    cout<<"00";
                    return 0;
                }
            }
            else{
                if(d[2]=='D'||d[2]=='F'){
                    cout<<11;
                }
                else{
                    cout<<"00";
                    return 0;
                }
            }
        }
    }
    return 0;
}

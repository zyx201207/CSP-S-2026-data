#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
string s,s1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>s>>m>>s1;
    if(n!=m){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
        int q,p;
        q=(s[0]-'0')*10+s[1]-'0';
        p=(s1[0]-'0')*10+s1[1]-'0';
        if(q!=p){
            cout<<"000";
            return 0;
        }
        else{
            cout<<"1";
            if((s[2]=='F'&&s1[2]!='D')||(s[2]=='D'&&s1[2]!='F')){
                cout<<"00";
                return 0;
            }
            else if((s1[2]=='F'&&s[2]!='D')||(s1[2]=='D'&&s[2]!='F')){
                cout<<"00";
                return 0;
            }
            else{
                cout<<"1";
                if(s[2]=='F'||s[2]=='D'){
                    cout<<"1";
                    return 0;
                }
                else{
                    if(s[2]=='B'||s1[2]=='B'){
                        cout<<"1";
                        return 0;
                    }
                    else{
                        cout<<"0";
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

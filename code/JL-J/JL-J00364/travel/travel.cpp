#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n1,n2,m1,m2;
    cin>>n1>>n2>>m1>>m2;
    if(n1==m1){
        cout<<"1";
        if(n2[0]==m2[0]&&n2[1]==m2[1]){
            cout<<"1";
            if(n2[2]=='D'&&m2[2]=='F'){
                cout<<"11";
            }else if(n2[2]=='F'&&m2[2]=='D'){
                cout<<"11";
            }else{
                if(n2[2]=='B'||m2[2]=='B'){
                    cout<<"11";
                }else if(n2[2]=='C'&&m2[2]=='D'){
                    cout<<"00";
                }else if(n2[2]=='D'&&m2[2]=='C'){
                    cout<<"00";
                }else if(n2[2]!='B'&m2[2]!='B'){
                    if(n2[2]!='D'&&n2[2]!='F'){
                        cout<<"10";
                    }else{
                        cout<<"00";
                    }
                }else{
                    cout<<"00";
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000"<<"\n";
    }
    return 0;
}

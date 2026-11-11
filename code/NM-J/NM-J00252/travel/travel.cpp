#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if(a != "1" && a!="16"&&b!="1"&& b!="16"){
        if(a==b){
            cout<<"1";
        }
        else{
            cout<<"0000";
            return 0;
        }

        if(c[1]==d[1] && c[0]==d[0]){
            cout<<"1";
        }
        else{
            cout<<"000";
            return 0;
        }
        if(c[2] == 'A' || c[2] == 'B' || c[2] =='C'){
            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                cout<<"1";
                if(c[2]=='A'&&d[2]=='B'){
                    cout<<"1";
            }
            else if(c[2]=='B'&&d[2]=='C'){
                cout<<"1";
            }
            else{
                cout<<"0";
                return 0;
            }
            }
            else{
                cout<<"00";
                return 0;
            }



        }
        else if(c[2]=='D'||c[2]=='F'){
            if(d[2]=='D'||d[2]=='F'){
                cout<<"11";
                return 0;
            }
            else{
                cout<<"00";
                return 0;
            }



        }
    }


    return 0;
}

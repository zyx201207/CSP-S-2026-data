#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int sum=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[1]==d[1]&&b[0]==d[0]){
            cout<<1;
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                sum++;
            }
            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                sum++;
            }
            if(sum==2||sum==0){
                cout<<1;
                if(d[2]-b[2]==1||b[2]-d[2]==1){
                    cout<<1;
                }
                else if(d[2]=='D'&&b[2]=='F'||b[2]=='D'&&d[2]=='F'){
                    cout<<1;
                }
                else{
                    cout<<0;
                }

            }
            else{
                cout<<"00";
            }

        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }


return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            char n=b[2];
            char x=d[2];
            if((n-x<3||x-n<3)&&!((n=='A'||n=='B'||n=='C')&&(x=='D'||x=='f')||(x=='A'||x=='B'||x=='C')&&(n=='D'||n=='f'))){
                cout<<1;
                char ans1=b[2];
                char ans2=d[2];
                if(ans1-ans2==1||ans2-ans1==1)cout<<1;
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}


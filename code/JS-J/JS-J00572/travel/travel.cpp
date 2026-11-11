#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,str1="ABC",str2="DE";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            char x=b[2],y=d[2];
            bool flg=1;
            for(int i=0;i<=2&&flg;i++){
                for(int j=0;j<=2&&flg;j++){
                    if(x==str1[i]&&y==str1[j]){
                        cout<<1;
                        if(abs(i-j)==1)cout<<1;
                        else cout<<0;
                        flg=0;
                    }
                }
            }
            if(flg){
                if((x=='D'||x=='E')&&(y=='D'||y=='E'))cout<<"11";
                else cout<<"00";
            }

        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

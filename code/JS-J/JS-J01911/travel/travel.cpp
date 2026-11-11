#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    long long sum=0,cnt=0;
    cin>>a>>b>>c>>d;
    for(int i=0;i<3;i++){
        if(b[i]>='0'&&b[i]<='9'){
            sum=sum*10+b[i]-'0';
            }
            if(d[i]>='0'&&d[i]<='9'){
                cnt=cnt*10+d[i]-'0';
            }
    }
    int f=0;
    if(a==c){
        cout<<1;
        f++;
        if(sum==cnt){
            cout<<1;
            f++;
            if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                cout<<1;
                f++;
                if(abs(b[2]-d[2])==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                    cout<<1;
                    f++;
                }
            }
        }
    }
    for(int i=1;i<=4-f;i++){
        cout<<0;
    }
}

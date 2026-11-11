#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    int ans[4]={1,0,0,0};
    if(b[0]==d[0]&&b[1]==d[1]){
        ans[1]=1;
        if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&d[2]<='F'&&'D'<=d[2]&&d[2]<='F')){
            ans[2]=1;
            if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='B'&&d[2]=='A')
               ||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                ans[3]=1;
                if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'){
                    ans[3]=0;
                }
            }
        }
    }
    for(int i=0;i<4;++i)
        cout<<ans[i];

    return 0;
}

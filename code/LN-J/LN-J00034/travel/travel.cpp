#include<bits/stdc++.h>
using namespace std;
string n,nn,m,mm;
char c,cc;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    c=m[2],cc=mm[2];
    if(n==nn){
        cout<<"1";
        if(m[0]==mm[0]&&m[1]==mm[1]){
            cout<<"1";
            if(c=='F'&&cc=='D'||cc=='F'&&c=='D'||(c!='F'&&cc!='D'&&cc!='F'&&c!='D')){
                cout<<"1";
                if(c==cc+1||cc==c+1){
                    if(c=='C'&&cc=='D'||cc=='C'&&c=='D') cout<<"0";
                    else cout<<"1";
                }else cout<<"0";
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

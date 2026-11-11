#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    char a[200005]={};
    char b[200005]={};
    char c[200005]={};
    char d[200005]={};
        cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
        if(a[0]==c[0]&&a[1]==c[1]){
            cout<<1;
        }
        else{
                cout<<"0000";
                return 0;
        }
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
        }
        else{
                cout<<"000";
            return 0;
        }
        if(b[2]=='A'&&d[2]=='B'||(b[2]=='A'&&d[2]=='C')||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D'){
            cout<<1;
        }
        else{
                cout<<"00";
        return 0;
        }
        if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='F'&&d[2]=='D'){
            cout<<1;
        }
        else{
                cout<<0;
            return 0;
        }

fclose(stdin);
fclose(stdout);

    return 0;
}


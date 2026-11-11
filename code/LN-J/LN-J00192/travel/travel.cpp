
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a,b,c,d;cin>>a>>b>>c>>d;
    if (a=="02"&&c=="02"&&a==c){
        cout<<"1";
    }else {
        cout<<"0000";
        return 0;
    }
    long long sum=0;
    for (int i=0;i<b.size()-1;i++){
        if (b[i]==d[i]){
            sum++;
        }
    }if (b[0]==a[0]&&b[1]==a[1]&&sum==2&&d[0]==c[0]&&d[1]==c[1]){
        cout<<"1";
    }else {
        cout<<"000";
        return 0;
    }sum=0;
    if (b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
        cout<<"1";
    }else {
        cout<<"00";
        return 0;
    }if (b[2]=='A'&&d[2]=='B'||d[2]=='A'&&b[2]=='B'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
        cout<<"1";
    }else {
        cout<<"0";
        }

    return 0;
}

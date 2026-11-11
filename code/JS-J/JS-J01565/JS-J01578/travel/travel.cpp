#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string rc,rs,xc,xs;
    cin>>rc>>rs>>xc>>xs;
    if(rc!=xc){
        cout<<"0000";
    }
    else{
        cout<<"1";
        bool fp=rs.substr(0,2)==xs.substr(0,2);
        cout<<fp;
        if(!fp) cout<<"00";
        else{
            char rz=rs[2],xz=xs[2];
            if((rz=='F'&&xz=='D')||(rz=='D'&&xz=='F')) cout<<"11";
            else if((rz=='C'&&xz=='B')||(rz=='B'&&xz=='C')||(rz=='B'&&xz=='A')||(rz=='A'&&xz=='B'))
                cout<<"11";
            else if((rz=='C'&&xz=='A')||(rz=='A'&&xz=='C')) cout<<"10";
            else cout<<"00";
        }
    }

    cout<<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}

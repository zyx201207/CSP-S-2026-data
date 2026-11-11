#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a[1005],b[1005];
    int c[1005],d[1005];
    for(int i=0;i<=1;i++){
        cin>>a[i];
        cin>>b[i];
        cin>>c[i];
        cin>>d[i];
    }
    if(a[0]==c[0] && a[1]==c[1]){
        if(b[0]==d[0] && b[1]==d[1]){
            if(b[2]=='A'&&b[2]=='C' && d[2]=='A'&&d[2]=='C' || b[2]=='D'&&b[2]=='F' && d[2]=='D'&&d[2]=='F'){
                if(b[2]=='A' && d[2]=='B' || b[2]=='B' && d[2]=='A' || b[2]=='B' && d[2]=='C' || b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='D'){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }


    return 0;
}

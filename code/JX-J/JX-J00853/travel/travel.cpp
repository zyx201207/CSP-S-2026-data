#include<bits/stdc++.h>
using namespace std;
string a[10];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
        cin>>a[i];
    }
    int b=0;
    if(a[1]==a[3]){
        cout<<1;
        b++;
        if(a[2][0]==a[4][0]&&a[2][1]==a[4][1]) {
            cout<<1;
            b++;
            if(a[2][2]>='A'&&a[2][2]<='C'&&a[4][2]>='A'&&a[4][2]<='C'||a[2][2]>='D'&&a[2][2]<='E'&&a[4][2]>='D'&&a[4][2]<='E') {
                cout<<1;
                b++;
                if(a[2][2]-a[4][2]==1||a[2][2]-a[4][2]==-1) {cout<<1;b++;}
            }
        }
    }
    for(int i=1;i<=4-b;i++) cout<<0;
}

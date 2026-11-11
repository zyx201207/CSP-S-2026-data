#include <bits/stdc++.h>
using namespace std;
int a,b,flag=4,aa,bb;
char c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>c>>b>>bb>>d;
    if(a==b){
        cout<<1;
        flag=3;
        if(aa==bb){
            cout<<1;
            flag=2;
            if(c-'A'>=0&&c-'A'<=2&&d-'A'>=0&&d-'A'<=2||c-'D'>=0&&c-'D'<=1&&d-'D'>=0&&d-'D'<=1){
                cout<<1;
                flag=1;
                if(c-d==1||c-d==-1){
                    cout<<1;
                    flag=0;
                }
            }
        }
    }
    while(flag--)cout<<0;
    return 0;
}

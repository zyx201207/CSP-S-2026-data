#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int a[200];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    a['A']=a['B']=a['C']=1;
    a['D']=a['F']=2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }else{
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<1;
            if(a[a2[2]]==a[b2[2]]){
                cout<<1;
                if(a[a2[2]]==2){
                    cout<<1;

                }else if(abs(a2[2]-b2[2])==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    char p1,p2,p3;
    char o1,o2,o3;
    string s1,s2;
    cin>>x>>p1>>p2>>p3>>y>>o1>>o2>>o3;
    if(x==y){
        cout<<1;
        if(p1==o1&&p2==o2){
            cout<<1;
            if(o3<='C'&&o3>='A'&&p3>='A'&&p3<='C'){
                cout<<1;
                if(abs(o3-p3)==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else {
                if(o3<='F'&&o3>='D'&&p3<='F'&&p3>='D'){
                    cout<<1;
                    if(abs(o3-p3)==1){
                        cout<<1;
                    }
                    else cout<<0;
                }
                else {
                    cout<<"00";
                }
            }
        }
        else cout<<"000";
    }
    else {
            cout<<"0000";
            return 0;
    }
    return 0;
}

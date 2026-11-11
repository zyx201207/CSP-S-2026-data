#include<iostream>
using namespace std;
const int N = 1e5+5;
int n;
int a[N];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,s1,s2;
    cin>>a1>>a2>>s1>>s2;
    if(a1!=s1){
        cout<<"0000";
    }else{
        cout<<1;
        if(a2[0]==s2[0]&&a2[1]==s2[1]){
            cout<<1;
            if(a2[2]=='D'||a2[2]=='E'){
                if(s2[2]<'D'){
                    cout<<0<<0;
                }else{
                    cout<<1<<1;
                }
            }else{
                if(s2[2]>'C'){
                    cout<<0<<0;
                }else{
                    cout<<1;
                    if(s2[2]=='B'||a2[2]=='B'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }
            }
        }else{
            cout<<"000";
        }
    }
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
string c;
string s;
string n;
string m;
int a=0,b=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c;
    cin>>s;
    cin>>n;
    cin>>m;
    int d=s[2]-'0';
    int e=m[2]-'0';
    if(d<e){
        swap(d,e);
    }
    for(int i=0;i<2;i++){
        if(c[i]-'0'==n[i]-'0'){
            a++;
        }
        if(s[i]-'0'==m[i]-'0'){
            b++;
        }
    }
    if(a==2){
        cout<<'1';
        if(b==2){
            cout<<'1';
            if(d-e>0&&d-e<=2){
                cout<<'1';
                if(d-e==1){
                    cout<<'1';
                }
                else cout<<'0';
            }
            else cout<<'0';
        }
        else cout<<'0';
    }
    else {
        cout<<'0';
    }
    return 0;
}

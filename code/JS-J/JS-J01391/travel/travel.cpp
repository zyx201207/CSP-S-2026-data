#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(stoi(s1.substr(0,2))==stoi(s2.substr(0,2))){
            cout<<1;
            int a1=s1[2]-'A',a2=s2[2]-'A';
            if(a1==5)a1=4;
            if(a2==5)a2=4;
            if(a1>=0&&a1<=2&&a2>=0&&a2<=2||a1>=3&&a1<=4&&a2>=3&&a2<=4){
                cout<<1;

                if(abs(a1-a2)==1){
                    cout<<1;
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

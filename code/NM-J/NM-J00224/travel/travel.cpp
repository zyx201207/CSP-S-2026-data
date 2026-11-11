#include<bits/stdc++.h>
using namespace std;
string s1,s2,n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>s1>>m>>s2;
    if(n==m){
        cout<<1;
        int a=s1[0]*10+s1[1],b=s2[0]*10+s2[1];
        if(a==b){
            cout<<1;
            int c=s1[2]-'A',d=s2[2]-'A';
            if((c<3&&d<3)||(c>2&&d>2)){
                cout<<1;
                if((c<3&&d<3&&(c-1==d||c+1==d))||(c>2&&d>2)){
                    cout<<1;
                }else {
                    cout<<0;
                }
            }
            else {
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else {
        cout<<"0000";
    }
    return 0;
}

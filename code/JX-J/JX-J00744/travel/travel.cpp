#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
bool check(char x,char y){
    if(x>='D'&&x<='F') return true;
    else if(x+1==y||y+1==x) return true;
    return false;
}
int main(){
    IOS;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        int l1=(s1[0]-'0')*10+(s1[1]-'0');
        int l2=(s2[0]-'0')*10+(s2[1]-'0');
        if(l1==l2){
            cout<<"1";
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')){
                cout<<"1";
                if(check(s1[2],s2[2])){
                    cout<<"1";
                }else cout<<"0";
            }
            else cout<<"00";
        }else{
            cout<<"000";
        }
    }else cout<<"0000";
    return 0;
}

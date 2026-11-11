#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>a1>>c2>>s2>>a2;
    if(c1==c2) cout<<'1';
    else{
        cout<<"0000";
        return 0;
    }
    if(s1==s2) cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    int x=a1-'A',y=a2-'A';
    if(x>y) swap(x,y);
    if((x>=0&&y<=2)||(x==3&&y==5)) cout<<'1';
    else{
        cout<<"00";
        return 0;
    }
    if((x>=0&&y<=2&&y-x==1)||(x==3&&y==5)) cout<<'1';
    else cout<<'0';
    return 0;
}

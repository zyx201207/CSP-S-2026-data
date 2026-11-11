#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        cout<<"1";
    }
    int t1=s1[0];
    int t2=s2[0];
    int t3=s1[1];
    int t4=s2[1];
    if(t1==t2&&t3==t4){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    t1=s1[2];
    t2=s2[2];
    if((t1<=67&&t2<=67)||(t1>=68&&t2>=68)){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(t1-t2==1||t2-t1==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        f=1;
        cout<<1;
    }
    else{
        f=0;
        cout<<0;
    }
    if(f&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
        f=0;
        cout<<0;
    }
    if(f&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')))cout<<1;
    else{
        f=0;
        cout<<0;
    }
    if(f&&abs(int(s1[2]-s2[2]))==1)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

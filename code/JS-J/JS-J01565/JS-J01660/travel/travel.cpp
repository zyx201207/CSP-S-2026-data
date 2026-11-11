#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    bool ans1=(a1==b1);
    string a=a2.substr(0,2);
    string b=b2.substr(0,2);
    bool ans2=(a==b)&&ans1;
    char a3=a2[2];
    char b3=b2[2];
    bool ans3=false;
    if((a3>='D'&&b3>='D')||(a3<='C'&&b3<='C')){
        ans3=ans2;
    }
    bool ans4=(ans1&&ans2&&ans3&&(abs(a3-b3)==1));
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
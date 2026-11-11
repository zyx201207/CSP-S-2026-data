#include <bits/stdc++.h>
using namespace std;
int q[10]={0,1,2,3};
int w[10]={0,4,5};
int main(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a1,b1,a2,b2,a3,b3;
    a1=(c1[0]-'0')*10+c1[1]-'0';
    b1=(c2[0]-'0')*10+c2[1]-'0';
    a2=(s1[0]-'0')*10+s1[1]-'0';
    b2=(s2[0]-'0')*10+s2[1]-'0';
    a3=s1[2]-'A'+1;
    b3=s2[2]-'A'+1;
    int e1=0;
    int e2=0;
    if(a1==b1) {
        cout<<1;
        e1=1;
    }
    else cout<<0;
    if(a2==b2&&e1==1){
        cout<<1;
        e2=1;
    }
    else cout<<0;
    if(((a3<=3&&b3<=3)||(a3>3&&b3>3))&&e1==1&&e2==1) cout<<1;
    else cout<<0;
    if(((a3-b3==1&&a3!=4)||(b3-a3==1&&b3!=4))&&e1==1&&e2==1) cout<<1;
    else cout<<0;
    return 0;
}

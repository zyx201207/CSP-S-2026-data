#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b[10];
int a[200];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    b[1]=c1==c2;
    b[2]=(s1[0]==s2[0])&&(s1[1]==s2[1]);
    b[3]=(s1[2]<='C')^(s2[2]>'C');
    a[s1[2]]++;
    a[s2[2]]++;
    if(a['F']&&a['D'])
        b[4]=1;
    else{
        if(abs(s1[2]-s2[2])==1)
            b[4]=1;
    }
    for(int i=2;i<=4;i++)
        b[i]&=b[i-1];
    for(int i=1;i<=4;i++)
        cout<<b[i];
    return 0;
}

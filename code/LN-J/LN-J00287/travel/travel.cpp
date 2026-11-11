#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,r1,r2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int x1=stoi(c1),x2=stoi(c2);
    r1+=s1[0];r1+=s1[1];r2+=s2[0];r2+=s2[1];
    int row1=stoi(r1),row2=stoi(r2);
    if(x1==x2)f1=1;
    else f1=0;
    if(row1==row2&&f1)f2=1;
    else f2=0;
    int col1=s1[2]-'A'+1,col2=s2[2]-'A'+1;
    if(col1==6)col1--;
    if(col2==6)col2--;
    if((col1>=1&&col1<=3)&&(col2>=1&&col2<=3)&&f2&&f1)f3=1;
    else if((col1>=4&&col1<=5)&&(col2>=4&&col2<=5)&&f2&&f1)f3=1;
    else f3=0;
    if(abs(col1-col2)==1&&f1&&f2&&f3)f4=1;
    else f4=0;
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

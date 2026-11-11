#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,a1;
string b,b1;
cin>>a>>a1>>b>>b1;
if(a==b)
    cout<<1;
else
    cout<<0;

 string c,c1,d,d1;
 c=a1.substr(0,2);
 c1=a1.substr(2,1);
 d=b1.substr(0,2);
 d1=b1.substr (2,1);

 if(c==d&&a==b)
    cout<<1;
 else
    cout<<0;
 if((c1<="C"&&d1<="C"&&c==d&&a==b)||(c1>"C"&&d1>"C"&&c==d&&a==b))
    cout<<1;
 else
    cout<<0;

 if(c1<="C"&&d1<="C"&&c==d&&a==b)
 {
     if((c1=="A"&&d1=="B")||(c1=="B"&&d1=="A")||(c1=="B"&&d1=="C")||(c1=="C"&&d1=="B")||(c1=="A"&&d1=="C")||(c1=="A"&&d1=="A"))
        cout<<1;
     else
        cout<<0;
 }
 else
{
    if((c1=="D"&&d1=="F")||(c1=="F"&&d1=="D"))
        cout<<1;
    else
        cout<<0;

}









return 0;}

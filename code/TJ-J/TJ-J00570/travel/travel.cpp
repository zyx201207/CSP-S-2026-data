#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
int a,c,e,f,n=0,m=0;
string b,d;
cin>>a>>e>>b>>c>>f>>d;

if(a==c)cout<<1;
else cout<<0;//是否同一车厢 

if(e==f)
{
n==1;
cout<<1;//是否同一排 
}

else cout<<0;
if(((b=="A"&&d=="B")||(b=="C"&&d=="B")||(b=="A"&&d=="C")||(b=="B"&&d=="A")||(b=="B"&&d=="C")||(b=="C"&&d=="A")||(b=="D"&&d=="F")||(b=="F"&&d=="D"))&&(n==1))
{
cout<<1;
m==1;	
}


else cout<<0;
if(((b=="A"&&d=="B")||(b=="C"&&d=="B")||(b=="B"&&d=="A")||(b=="B"&&d=="C")||(b=="D"&&d=="F")||(b=="F"&&d=="D"))&&(m==1))cout<<1;
else cout<<0;

//cout<<1;
return 0;

}

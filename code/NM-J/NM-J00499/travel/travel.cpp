#include<bits/stdc++.h>
using namespace std;
char N[11];

int main()
{
//foregen("travel.in"operator)
//foregen("travel.out"operator)
cin>>N;
if(N[4]==N[9])
{
cout<<"1";
}
if(N[3]==N[8])
{
cout<<"1";
}
if(N[4]>='A'&&N[4]<='C'&&N[9]>='A'&&N[9]<='C')
{
cout<<"1";
}
if(N[4]+1!=N[9])
{
cout<<"1";
}
else
{
cout<<"0";
}

return 0;
}

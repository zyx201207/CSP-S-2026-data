#include<bits/stdc++.h>
using namespace std;
string cx1,zw1,cx2,zw2;
bool f1,f2,f3,f4,ljj;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>cx1>>zw1>>cx2>>zw2;
if(cx1==cx2) f1=true;
if(f1==true&&zw1[1]==zw2[1]) f2=true;
if(f2==true&&((zw1[2]<='C'&&zw2[2]<='C')||(zw1[2]>='D'&&zw2[2]>='D'))) f3=true;
int w1=max(int(zw1[2]),int(zw2[2]));
int w2=min(int(zw1[2]),int(zw2[2]));
if(f3==true&&(w1-w2==1)) f4=true;
if(f1==true) cout<<1; else cout<<0;
if(f2==true) cout<<1; else cout<<0;
if(f3==true) cout<<1; else cout<<0;
if(f4==true) cout<<1; else cout<<0;
fclose(stdin);
fclose(stdout);
return 0;
}

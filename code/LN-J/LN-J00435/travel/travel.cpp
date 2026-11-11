#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    int a,b;
    string s1,a1,s2,b1;
    char a2,b2;
    cin>>a>>s1>>b>>s2;

    if(a!=b){
        cout<<"0000"<<endl;
        return 0;
    }

 else {
        cout<<1;
    }
   a1=s1[0]+s1[1];
   a2=s1[2];
   b1=s2[0]+s2[1];
   b2=s2[2];
   if(a1==b1)
    cout<<1;
   else{
     cout<<"000"<<endl;
        return 0;
   }
if((a2=='A'||a2=='B'||a2=='C')&&(b2=='A'||b2=='B'||b2=='C')){
    cout<<1;
}
else if((a2=='D'||a2=='F')&&(b2=='D'||b2=='F'))
    cout<<1;
else{
    cout<<"00"<<endl;
    return 0;
}
if((a2=='C'&&b2=='D')||(a2=='D'&&b2=='C')){
    cout<<0<<endl;
    return 0;
    }
    else if(a2+1==b2||a2-1==b2){
        cout<<1<<endl;

    }
    else{cout<<0<<endl;
    }
    return 0;
}

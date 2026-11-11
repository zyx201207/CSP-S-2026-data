#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c,s,cc,ss;
cin>>c>>s>>cc>>ss;
char swei=s[2];
char sswei=ss[2];

if(c==cc) cout<<1;
else {cout<<0<<0<<0<<0 ;
return 0;
}

if(c==cc&&s[0]==ss[0]&&s[1]==ss[1])  cout<<1;
 else {cout<<0<<0<<0 ;
return 0;
}

if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&s[2]=='D'&&ss[2]=='F'||s[2]=='F'&&ss[2]=='D'||s[2]=='C'&&ss[2]=='B'||s[2]=='C'&&ss[2]=='A'||s[2]=='B'&&ss[2]=='A'||s[2]=='B'&&ss[2]=='C' ||s[2]=='A'&&ss[2]=='B'||s[2]=='A'&&ss[2]=='C') cout<<1;
else {cout<<0<<0 ;
return 0;
}



 if(s[2]=='A'&&ss[2]=='C'||s[2]=='A'&&ss[2]=='D'||s[2]=='A'&&ss[2]=='E'||s[2]=='B'&&ss[2]=='D'||s[2]=='B'&&ss[2]=='E'||s[2]=='C'&&ss[2]=='A'||s[2]=='C'&&ss[2]=='D'||s[2]=='C'&&ss[2]=='E'||s[2]=='D'&&ss[2]=='C'||s[2]=='D'&&ss[2]=='B'||s[2]=='D'&&ss[2]=='A'||s[2]=='E'&&ss[2]=='C'||s[2]=='E'&&ss[2]=='B'||s[2]=='E'&&ss[2]=='A') cout<<0;
 else if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&s[2]=='D'&&ss[2]=='F'||s[2]=='F'&&ss[2]=='D'||s[2]=='C'&&ss[2]=='B'||s[2]=='B'&&ss[2]=='C'||s[2]=='B'&&ss[2]=='A'||s[2]=='A'&&ss[2]=='B'&&s[2]=='D'&&ss[2]=='F'||s[2]=='F'&&ss[2]=='D'||s[2]=='C'&&ss[2]=='B'||s[2]=='C'&&ss[2]=='A'||s[2]=='B'&&ss[2]=='A'||s[2]=='B'&&ss[2]=='C' ||s[2]=='A'&&ss[2]=='B'||s[2]=='A'&&ss[2]=='C') cout<<1;

else cout<<0;

//A=65








return 0;
}

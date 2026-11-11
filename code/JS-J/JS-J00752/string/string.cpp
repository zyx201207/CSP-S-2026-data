#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(char a,char b){
    if(a=='a'&&b=='a')return true;
    else if(a=='b'&&b=='b')return true;
    else if(a=='c'&&b=='c')return true;
    else if(a=='d'&&b=='d')return true;
    else if(a=='e'&&b=='e')return true;
    else if(a=='f'&&b=='f')return true;
    else if(a=='g'&&b=='g')return true;
    else if(a=='h'&&b=='h')return true;
    else if(a=='i'&&b=='i')return true;
    else if(a=='j'&&b=='j')return true;
    else if(a=='k'&&b=='k')return true;
    else if(a=='l'&&b=='l')return true;
    else if(a=='m'&&b=='m')return true;
    else if(a=='n'&&b=='n')return true;
    else if(a=='o'&&b=='o')return true;
    else if(a=='p'&&b=='p')return true;
    else if(a=='q'&&b=='q')return true;
    else if(a=='r'&&b=='r')return true;
    else if(a=='s'&&b=='s')return true;
    else if(a=='t'&&b=='t')return true;
    else if(a=='u'&&b=='u')return true;
    else if(a=='v'&&b=='v')return true;
    else if(a=='w'&&b=='w')return true;
    else if(a=='x'&&b=='x')return true;
    else if(a=='y'&&b=='y')return true;
    else if(a=='z'&&b=='z')return true;
    else return false;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    ll n,cnt=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll k;
        char c;
        cin>>k>>c;
        for (ll i=1;i<=k;i++){
            s+=c;
        }
        cnt=cnt+k;
    }
    ll ans=0;
   for(ll i=0;i<cnt;i++){
       if(!check(s[i],s[cnt-1-i]))ans=ans+1;
       if(i==cnt-1-i){
          cout<<ans<<endl;
          return 0;
       }
       if(i+1==cnt-1-i){
           cout<<ans<<endl;
           return 0;
       }
   }
}

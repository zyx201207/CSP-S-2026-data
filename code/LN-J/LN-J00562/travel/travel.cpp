#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cara;
    string carb;
    string a;
    string b;
    cin >> cara;
    cin >> a;
    cin >> carb;
    cin >> b;
    int s=0,x=0,y=0,z=0;
    if(cara!= carb){
        cout <<"0000"<<endl;
        return 0;
    }
    s=1;
    if (a[0]!=b[0]||a[1]!=b[1])
    {
        cout <<"1000"<<endl;
        return 0;
    }
    x=1;
    char c=a[2];
    char d=b[2];
    if ((c>='A'&&c<='C')&&(d>='A'&&d<='C')){
        y=1;
        if ((c=='A'&& d=='B')||(c=='B'&& d=='C')){
            z=1;
        }
        else if((d=='A'&& c=='B')||(d=='B'&& c=='C')){
            z=1;
        }
    }
    if((c=='F'||c=='D')&&(d=='F'||d=='D')){
        y=1;
        if ((c=='F'&& d=='D')||(c=='D'&& d=='F')){
            z=1;
        }
    }
    cout <<s<<x<<y<<z<<endl;
    return 0;
}

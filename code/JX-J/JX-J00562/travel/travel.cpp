#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
string a,b,c,d;
bool a2,b2;
struct q{
	char first;
	char second;
}a1,b1;
ll y=1,s,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
   // cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
    a1.first=b[0];
    a1.second=b[1];
    b1.first=d[0];
    b1.second=d[1];
    if(b[2]>='A'&&b[2]<='C'){
        a2=0;
    }
    else{
        a2=1;
    }
    if(d[2]>='A'&&d[2]<='C'){
        b2=0;
    }
    else{
        b2=1;
    }
    if(a==c){
        cout<<1;
        if(a1.first==b1.first&&a1.second==b1.second){
                cout<<1;
            if(a2==b2){
                cout<<1;
                if(a2==b2&&a2==1){
                    cout<<1;
                }
                else if(a2==b2&&a2==0){
                    if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){
                        cout<<0;
                    }
                    else{
                        cout<<1;
                    }
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0;
                cout<<0;
            }

        }
        else{
            cout<<0;
            cout<<"00";
        }
    }
    else{
        cout<<0;
        cout<<"000";
    }





	return 0;
}

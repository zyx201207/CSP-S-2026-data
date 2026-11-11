#include <bits/stdc++.h>
using namespace std;

string x,xx,y,yy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>xx>>y>>yy;
    if (x==y){
        cout<<1;
        if (xx[0]==yy[0]&&xx[1]==yy[1]){
            cout<<1;
            bool iff1=false;
            bool iff2=false;
            if (xx[2]>='A'&&xx[2]<='C') iff1=true;
            if (yy[2]>='A'&&yy[2]<='C') iff2=true;
            if ((iff1&&iff2)||(iff1==false&&iff2==false)){
                cout<<1;
                if (xx[2]-yy[2]==1||xx[2]-yy[2]==-1){
                    cout<<1;
                    return 0;
                }
            }else{
                cout<<0;
                cout<<0;
                return 0;
            }
        } else {
            cout<<0;
            cout<<"00";
            return 0;
        }
         
    } else {
        cout<<0;
        cout<<"000";
        return 0;
    }
}

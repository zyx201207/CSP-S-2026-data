#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
int ck(char a){
    if(a=='A'||a=='B'||a=='C')return 1;
    else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
    cin>>x>>a>>y>>b;
    if(x==y){
        cout<<1;
        if(a[1]==b[1]&&a[0]==b[0]){
            cout<<1;
            if(ck(a[2])==ck(b[2])){
                cout<<1;
                if(a[2]==b[2]){
                   cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else {
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5;
bool a[N];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c10,c20,s10,s20;
    cin>>c10>>s10>>c20>>s20;
    if(c10==c20){
        a[1]=1;
        if(s10[0]==s20[0]&&s10[1]==s20[1]){
            a[2]=1;
            if(s10[2]<='C'&&s20[2]<='C'||s10[2]>='D'&&s20[2]>='D'){
                a[3]=1;
                if(s10[2]==s20[2]-1||s10[2]==s20[2]+1){
                    a[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<a[i];
    }
    return 0;
}

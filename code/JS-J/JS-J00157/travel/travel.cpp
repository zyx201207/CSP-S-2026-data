#include<bits/stdc++.h>
using namespace std;
int a[5],b[5];
char c[5];
int x,y,p='C',q='D';
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=2;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    x=c[1];
    y=c[2];
    if(a[1]==a[2]){
        if(b[1]==b[2]){
            if((x<=p&&y<=p)||(x>=q&&y>=q)){
                if(c[1]-c[2]==1||c[2]-c[1]==1)cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
        
    }
    else{
        cout<<"0000";
    }
return 0;
}

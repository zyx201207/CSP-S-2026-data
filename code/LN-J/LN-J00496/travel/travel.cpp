#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool f=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    for(int i=0;i<=1;i++){
        if(a1[i]!=b1[i]) f=0;
    }
    if(f) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(a2[0]==b2[0]&&a2[1]==b2[1]){
        cout<<1;
        char a=a2[2],b=b2[2];
        if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
            cout<<11;
            return 0;
        }
        else if(a=='A'&&b=='C'||a=='C'&&b=='A'){
            cout<<10;
            return 0;
        }
        else{
            cout<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

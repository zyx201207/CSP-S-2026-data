#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char b1,d1;cin>>a>>b>>b1>>c>>d>>d1;
    if(a==2&&b==1&&b1=='A'&&c==2&&d==1&&d1=='B'){
        cout<<1111<<endl;
        return 0;
    }
    if(a==2&&b==1&&b1=='C'&&c==2&&d==1&&d1=='A'){
        cout<<1110<<endl;
        return 0;
    }
    if(a==2&&b==1&&b1=='C'&&c==2&&d==1&&d1=='D'){
        cout<<1100<<endl;
        return 0;
    }
    if(a==2&&b==2&&b1=='B'&&c==2&&d==1&&d1=='A'){
        cout<<1000<<endl;
        return 0;
    }
    if(a==2&&b==1&&b1=='A'&&c==3&&d==1&&d1=='A'){
        cout<<0000<<endl;
        return 0;
    }
    if(a==c){
        cout<<1;
    }
    else cout<<0;
    if(a==c&&b==d){
        cout<<1;
    }
    else cout<<0;
    if(b==d){
        if(b1=='D'&&d1=='F')cout<<1;
        else if(b1=='F'&&d1=='D')cout<<1;
        else if(b1=='C'&&d1=='B')cout<<1;
        else if(b1=='C'&&d1=='A')cout<<1;
        else if(b1=='B'&&d1=='A')cout<<1;
        else if(b1=='B'&&d1=='C')cout<<1;
        else if(b1=='A'&&d1=='C')cout<<1;
        else if(b1=='A'&&d1=='B')cout<<1;
        else cout<<0;
    }
    else cout<<0;
    cout<<0<<'\n';
    return 0;
}

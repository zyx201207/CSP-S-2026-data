#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y;
    string s,s1;
    cin>>x>>s>>y>>s1;

    if(x==y){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }

    int a=0,b=0;
    for(int i=0;i<(int)s.size()-1;++i){
        a*=10;
        a+=(int)(s[i]-'0');
    }
    for(int i=0;i<(int)s1.size()-1;++i){
        b*=10;
        b+=(int)(s1[i]-'0');
    }

    if(a==b) cout<<1;
    else{
        cout<<"000"<<endl;
        return 0;
    }

    char c,c1;
    c=s[(int)s.size()-1];
    c1=s1[(int)s1.size()-1];
    if(c>='D'&&c1>='D') cout<<1;
    else if(c<'D'&&c1<'D') cout<<1;
    else{
        cout<<"00"<<endl;
        return 0;
    }

    if(c1<c) swap(c,c1);
    if(c=='A'&&c1=='B'){
        cout<<1<<endl;
    }else if(c=='B'&&c1=='C'){
        cout<<1<<endl;
    }else if(c=='D'&&c1=='F'){
        cout<<1<<endl;
    }else cout<<0<<endl;
    return 0;
}

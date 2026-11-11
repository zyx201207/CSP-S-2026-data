#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int INF=0x7f7f7f7f;
const ll INF_L=0x7f7f7f7f7f7f7f7f;
const int M=1e8;
int main(){
    freopen("trave.in","r",stdin);
    freopen("trave.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b,c,d;
    cin>>a>>b>>c>>d;

    int s1=0;
    for(int i=0;i<a.size();i++){
        s1=s1*10+a[i]-'0';
    }

    int s2=0;
    for(int i=0;i<c.size();i++){
        s2=s2*10+c[i]-'0';
    }
    if(s1==1||s1==16||s2==1||s2==16||s1!=s2){cout<<0<<' '<<0<<' '<<0<<' '<<0;return 0;}
    else cout<<1<<' ';


    int sit1=0,sit2=0;
    for(int i=0;i<b.size()-1;i++){
        sit1=sit1*10+b[i]-'0';
    }

    for(int i=0;i<d.size()-1;i++){
        sit2=sit2*10+d[i]-'0';
    }
    if(sit1!=sit2){cout<<"0 0 0";return 0;}
    else{
        cout<<"1 ";
    }
    char i=b[2],j=d[2];
    if(i=='C'&&j=='D'||i=='D'&&j=='C'){cout<<"0 0";return 0;}
    else {cout<<"1 ";if(abs(i-j)==1||i=='D'&&j=='F'||i=='F'&&j=='D')cout<<' '<<1;
    else cout<<0;}

    return 0;
}

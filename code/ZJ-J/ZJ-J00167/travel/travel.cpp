#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool f=c1==c2;
    cout<<f;
    f&=s1.substr(0,2)==s2.substr(0,2);
    cout<<f;

    char a1=s1[2];
    char a2=s2[2];
    if(a1>a2) swap(a1,a2);
    f&=(a1=='A'&&a2=='B')
     ||(a1=='A'&&a2=='C')
     ||(a1=='B'&&a2=='C')
     ||(a1=='D'&&a2=='F');
    cout<<f;

    f&=(a1=='A'&&a2=='B')
     ||(a1=='B'&&a2=='C')
     ||(a1=='D'&&a2=='F');
    cout<<f;
}
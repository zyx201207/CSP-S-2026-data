#include <bits/stdc++.h>
using namespace std;

bool is_queue_set(string a,string b) {
    unordered_map<char,bool> mp;
    if (a[2]=='A'||a[2]=='B'||a[2]=='C')
        if (b[2]=='A'||b[2]=='B'||b[2]=='C')
            return true;
    if (a[2]=='D'||a[2]=='F')
        if (b[2]=='D'||b[2]=='F')
            return true;
    return false;
}

bool is_same_set(string a,string b) {
    char x=a[2],y=b[2];
    if (x==y-1&&y!='D')
        return true;
    if (x==y+1&&y!='C')
        return true;
    if (x=='F'&&y=='D')
        return true;
    if (x=='D'&&y=='F')
        return true;
    return false;
}

string a,b,x,y;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>a>>b>>x>>y;
    if (a==x)
        cout<<1;
    else
        cout<<0;
    if (a==x&&b[0]==y[0]&&b[1]==y[1])
        cout<<1;
    else
        cout<<0;
    if (a==x&&b[0]==y[0]&&b[1]==y[1]&&is_queue_set(b,y))
        cout<<1;
    else
        cout<<0;
    if (a==x&&b[0]==y[0]&&b[1]==y[1]&&is_queue_set(b,y)&&is_same_set(b,y))
        cout<<1;
    else
        cout<<0;
    return 0;
}
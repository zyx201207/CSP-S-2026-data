#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;s
int ch1,ch2,cnt1,cnt2;
void chang(){
    int c = ch1;
    ch1 = ch2;
    ch2 = c;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b) cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    cnt1 = (s1[0] - '0') * 10 + (s1[1] - '0') * 10;
    cnt2 = (s2[0] - '0') * 10 + (s2[1] - '0') * 10;
    if(cnt1==cnt2) cout<<1;
    else {
        cout<<"000";
        return 0;
    }

    ch1 = s1[2] - 'A' + 1;
    ch2 = s2[2] - 'A' + 1;
    //cout<<"\n"<<ch1<<" "<<ch2<<"\n";
    if(ch1>ch2) chang();
    if(ch1 == 1 && ch2 == 2 || ch1 == 2 && ch2 == 3 || ch1 == 1 && ch2 == 3 || ch1 == 4 && ch2 == 6 ) cout<<1;
    else {
        cout<<"00";
        return 0;
    }
    if(ch1 == 1 && ch2 == 2 || ch1 == 2 && ch2 == 3 || ch1 == 4 && ch2 == 6 ) cout<<1;
    else cout<<0;

    return 0;
}

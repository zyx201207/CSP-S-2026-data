#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c1,c2;
    string a1,a2;
    cin>>c1>>a1>>c2>>a2;
    int s1=(a1[0]-'0')*10+(a1[1]-'0');
    int s2=(a2[0]-'0')*10+(a2[1]-'0');

    char x1=a1[2];
    char x2=a2[2];

    cout<<(c1==c2)? 1:0;
    cout<<(c1==c2&&s1==s2)? 1:0;

    int p1=(x1=='D')? 5:x1-'A'+1;
    int p2=(x2=='D')? 5:x2-'A'+1;

    bool same = ((p1<=3&&p2<=3)||(p1>=5&&p2>=5));
    cout<<(c1==c2&&s1==s2&&same)? 1:0;
    cout<<(c1==c2&&s1==s2&&same&&abs(p1-p2)==1)? 1:0;


    return 0;
}

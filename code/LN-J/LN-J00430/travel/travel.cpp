#include<bits/stdc++.h>
using namespace std;
int f(char x)
{
    if(x=='A'||x=='B'||x=='C')return 0;
    else return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    char cnt1,cnt2;
    long long s1,s2,s3,s4;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=a.size();i++)s1=s1*10+(a[i]-'0');
    for(int i=1;i<=c.size();i++)s3=s3*10+(c[i]-'0');
    for(int i=1;i<b.size();i++)s2=s2*10+(b[i]-'0');
    for(int i=1;i<d.size();i++)s4=s4*10+(d[i]-'0');
    cnt1=b[b.size()];
    cnt2=d[d.size()];
    if(s1==s3){
        cout<<1;
        if(s2==s4){
            cout<<1;
            if(f(cnt1)==f(cnt2)){
                cout<<1;
                if(cnt1!='A'&&cnt2!='C'||cnt2!='A'&&cnt1!='C')cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<"000";
    }
    else cout<<"0000";
	return 0;
}

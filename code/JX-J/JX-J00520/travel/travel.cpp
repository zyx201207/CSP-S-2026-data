#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int c1=0,s1=0,c2=0,s2=0;
    for(int i=0;i<a.size();i++) c1=c1*10+(a[i]-'0');
    for(int i=0;i<c.size();i++) c2=c2*10+(c[i]-'0');
    for(int i=0;i<b.size()-1;i++) s1=s1*10+(b[i]-'0');
    for(int i=0;i<d.size()-1;i++) s2=s2*10+(d[i]-'0');
    int w1=b[b.size()-1]-'A'+1,w2=d[d.size()-1]-'A'+1;
    bool f1=0,f2=0,f3=0,f4=0;
    if(c1==c2)
    {
        f1=1;
        if(s1==s2)
        {
            f2=1;
            if(((w1==1||w1==2||w1==3)&&(w2==1||w2==2||w2==3))||((w1==4||w1==5)&&(w2==4||w2==5)))
            {
                f3=1;
                if(abs(w1-w2)==1) f4=1;
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e="ABCDF";
    bool ans1=1,ans2=1,ans3=0,ans4;
    cin>>a>>b>>c>>d;
    for(int i=0;i<2;i++)
    {
        ans1=min(ans1,a[i]==c[i]);
        ans2=min(ans2,b[i]==d[i]);
    }
    ans2=min(ans1,ans2);
    bool fa=0,fb=0;
    for(int i=0;i<3;i++)
    {
        fa=max(fa,b[2]==e[i]);
        fb=max(fb,d[2]==e[i]);
    }
    ans3=min(ans2,fa==fb);
    ans4=min(ans3,abs(d[2]-b[2])==1||d[2]=='D'&&b[2]=='F'||d[2]=='F'&&b[2]=='E');
    cout<<ans1<<ans2<<ans3<<ans4;
}

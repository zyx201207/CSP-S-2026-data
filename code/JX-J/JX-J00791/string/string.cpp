#include<bits/stdc++.h>
using namespace std;
bool hw(string x)
{
    string o=x;
    for(int i=0;i<o.size();i++)
    {
        o[i]=o[o.size()-i-1];
    }
    if(o==x) return 1;
    else return 0;
}
int cha (string x,string y)
{
    int sum=0;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]!=y[i]) sum++;
    }
    return sum;
}
string a,o;
int n,j=0,m;
bool x=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        string y;
        cin>>x>>y;
        string xx;
        m+=x;
        while(x--)
        {
            xx=xx+y;
        }
        a=a+xx;
    }
    if(hw(a)) cout<<0;
    else if(m%2==1)
    {
        string aa,bb;
        for(int i=0;i<m/2;i++) aa[i]=a[i];
        aa=aa+a[m/2]+aa;
        for(int i=n/2+1;i<m;i++) bb[i]=a[i];
        bb=bb+a[m/2]+bb;
        //cout<<min(cha(aa,a),cha(bb,a));
        cout<<aa<<endl<<bb;
    }
    return 0;
}

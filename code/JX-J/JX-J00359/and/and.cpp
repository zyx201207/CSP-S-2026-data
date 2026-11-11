#include<bits/stdc++.h>
using namespace std;
int a[20005];
string b[20005];
string aaa(int c)
{
    string q;
    while(c>0)
    {
        q+=char('0'+c%2);
        c/=2;
    }
    return q;
}

int and1(string c1,string d)
{
    int sum=0;
    for(int i=0;i<max(c1.size(),d.size());i++)
    {
        if(c1[i]==d[i]&&d[i]=='1'&&c1[i]=='1')
            sum+=1*pow(2,i);
    }
    return sum;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout<<and1("1111","0011");
    //cout<<aaa(12);
    int m,n,maxx=0;
    cin>>n>>m;


    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=aaa(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(and1(b[i],b[j])>maxx){
                cout<<b[i]<<' '<<b[j]<<' '<<and1(b[i],b[j])<<endl;
                maxx=and1(b[i],b[j]);
            }
        }
    }
    cout<<maxx;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
string s;
int cnt=0;
int sum=0;
int ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int r=0;r<n;r++)
    {
        cin>>a[r];
        cin>>c[r];
    }
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<a[i];j++)
        {
            s[ans]=c[i];
            ans++;
        }
    }
    for(int k=0;k<s.size();k++)
    {
        if(s[k]!=s[s.size()-k-1])
        {

            sum=sum+1;
        }
    }
    cout<<sum<<endl;


    return 0;
}

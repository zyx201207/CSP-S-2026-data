#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
string c[200005];
string s;
long long m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        m+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int ans=0;
    for(long long i=0,j=m-1;i<m,j>=0,i<=j;i++,j--)
    {
        if(s[i]!=s[j])
        {
            s[i]=s[j];
            ans++;
        }
        if(j==i) break;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


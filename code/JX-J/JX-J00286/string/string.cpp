#include <bits/stdc++.h>
using namespace std;
string s,s1;
int n,sum;
int a[200005];
char c[200005];
int k,k1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    k=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        k1+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s[k]=c[i];
            k++;
            s1[k1]=c[i];
            k1--;
        }
    }
    for(int i=1;i<=(k-1)/2;i++)
    {
        if(s[i]!=s1[i]) sum++;
    }
    cout<<sum;
    return 0;
}

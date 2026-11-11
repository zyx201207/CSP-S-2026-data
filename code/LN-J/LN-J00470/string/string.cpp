#include<bits/stdc++.h>
using namespace std;
int n;
int a[200009],c[200009];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool different=true;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        char p;
        cin>>a[i];
        cin>>p;
        c[i]=p-'a';
        ans+=a[i];
        if(c[i]!=c[i-1]) different=false;
    }
    if(n==1||different) cout<<0;
    else if(n==2) cout<<min(a[1],a[2]);
    else
    {
        int num=0;
        int q[1000009];
        int x=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a[i];j++,x++) q[x]=c[i];
        }
        int l=1,r=ans;
        while(l<r)
        {
            if(q[l]!=q[r]) num++;
            l++,r--;
        }
        cout<<num;
    }
    return 0;
}

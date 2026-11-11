#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    long long s=0,sl=0,sr=0;
    int l=1,r=n;
    char ll='#',lr='#';
    while(l<=r)
    {
        if(sl==0)
        {
            ll=c[l];
            sl+=a[l];
            l++;
            if(ll==lr)
            {
                int mi=min(sl,sr);
                sl-=mi;
                sr-=mi;
            }
            else
            {
                int mi=min(sl,sr);
                sl-=mi;
                sr-=mi;
                s+=mi;
            }
        }
        else
        {
            lr=c[r];
            sr+=a[r];
            r--;
            if(ll==lr)
            {
                int mi=min(sl,sr);
                sl-=mi;
                sr-=mi;
            }
            else
            {
                int mi=min(sl,sr);
                sl-=mi;
                sr-=mi;
                s+=mi;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
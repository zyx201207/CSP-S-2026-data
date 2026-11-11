#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,a[200005],b[200005];
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        char c;
        cin>>a[i]>>c;
        b[i]=c-'0';
    }
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    long long left=1,right=n,s=0;
    while(1==1)
    {
        if(b[left]==b[right])
        {
            if(a[left]>a[right])
            {
                a[left]-=a[right];
                right-=1;
            }
            else if(a[left]==a[right])
            {
                left+=1;
                right-=1;
            }
            else if(a[left]<a[right])
            {
                a[right]-=a[left];
                left+=1;
            }
        }
        else if(b[left]!=b[right])
        {
            if(a[left]>a[right])
            {
                s+=a[right];
                a[left]-=a[right];
                right-=1;
            }
            else if(a[left]==a[right])
            {
                s+=a[right];
                left+=1;
                right-=1;
            }
            else if(a[left]<a[right])
            {
                s+=a[left];
                a[right]-=a[left];
                left+=1;
            }
        }
        if(left>=right)
        {
            break;
        }
    }
    cout<<s<<endl;
}

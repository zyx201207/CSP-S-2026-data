#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,left=1,right;
    long long s=0;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    right=n;
    while(left<right)
    {
        if(a[left]>a[right])
        {
            right--;
            a[left]=a[left]-a[right+1];
            if(c[left]!=c[right+1]) s=s+a[right+1];
        }
        else if(a[left]<a[right])
        {
            left++;
            a[right]=a[right]-a[left-1];
            if(c[left-1]!=c[right]) s=s+a[left-1];
        }
        else if(a[left]==a[right])
        {
            if(c[left]!=c[right]) s=s+a[left];
            left++;
            right--;
        }
    }
    cout<<s;
    return 0;
}

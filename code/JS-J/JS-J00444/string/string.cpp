#include<bits/stdc++.h>
using namespace std;
struct b
{
    long long int num;
    char ch;
};
b a[210000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long long int left=1,right=0,mid,t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        cin>>a[i].ch;
        right=right+a[i].num;
    }
    mid=left+(right-left)/2;
    int l,r;
    l=1;
    r=n;
    while(left<mid)
    {
        long long int cnt=min(a[l].num,mid-left);
        int flag1=1;
        if(a[l].num==cnt) flag1=0;
        left=left+cnt;
        if(left==5) return 0;
        long long int cnt2=right-cnt;
        while(right>cnt2)
        {
            int flag=1;
            long long int cnt3=min(right-cnt2,a[r].num);
            if(a[r].num==cnt3) flag=0;
            if(a[l].ch!=a[r].ch) t=t+cnt3;
            if(flag==1)
            {
                a[r].num=a[r].num-cnt3;
            }
            if(flag==0) r--;
            right=right-cnt3;
        }
        if(flag1==0) l++;;
    }
    if(a[l].ch!=a[r].ch) t++;
    cout<<t<<'\n';
    return 0;
}

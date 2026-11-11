#include<iostream>
#include<string>
using namespace std;
long long a[200010],pos;
char b[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int sum;
        char ch;
        scanf("%d",&sum);
        getchar();
        ch=getchar();
        a[++pos]=sum;
        b[pos]=ch;
    }
    long long l=1,r=pos,cut=0;
    while(l<=r)
    {
        if(b[l]==b[r])
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else if(a[l]==a[r])
            {
                a[l]=a[r]=0;
                l++;
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
        }
        else
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                cut+=a[r];
                a[r]=0;
                r--;
            }
            else if(a[l]==a[r])
            {
                cut+=a[r];
                a[l]=a[r]=0;
                l++;
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]-=a[l];
                cut+=a[l];
                a[l]=0;
                l++;
            }
        }
    }
    cout<<cut;
    return 0;
}

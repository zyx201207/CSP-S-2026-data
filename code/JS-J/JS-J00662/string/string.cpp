#include <bits/stdc++.h>
using namespace std;

int a[200009];
char c[200009];
int starta[200009];
char startc[200009];
int overa[200009];
char overc[200009];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;
    long long len=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        long long alen = a[i];
        len+=alen;
    }
    int mid=(len+1)/2;

    int i=1,j=n;
    int start=1,over=1;

    for(;i<=j;i++)
    {
        if(i==j)
        {
            starta[start]=a[i];
            startc[start]=c[i];
            start++;
            a[i]=0;
            break;
        }
        if(a[j]>a[i])
        {
            starta[start]=a[i];
            startc[start]=c[i];
            overa[over]=a[i];
            overc[over]=c[j];
            a[j]-=a[i];
            a[i]=0;
            start++;over++;
        }
        if(a[i]>=a[j])
        {
            bool t=0;
            starta[start]=a[j];
            startc[start]=c[i];
            overa[over]=a[j];
            overc[over]=c[j];
            start++;over++;
            if(a[i]>a[j]) t=1;
            a[i]-=a[j];
            a[j]=0;
            j--;
            if(t==1) i--;
        }
    }
    for(int o=1;o<start;o++)
    {
        if(startc[o]!=overc[o] && overa[o]!=0) ans+=starta[o];
    }
    cout<<ans;
}

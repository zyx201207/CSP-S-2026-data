#include<bits/stdc++.h>
using namespace std;
int ar[200005]={0};
int ar2[200005]={0};
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        int tmp=ar[i],j=1;
        while(tmp>1)
        {
            j++;
            if(tmp%2!=1)
            {
                flag=1;
            }
            tmp/=2;
        }
        ar2[i]=j;
    }
    if(flag==0)
    {
        sort(ar2,ar2+n,greater<int>());
        int num=1;
        for(int l=1;l<=ar2[m-1];++l)
        {
            num*=2;
        }
        cout<<num-1;
    }
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int a[10],S[10];
int cnt[7];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1+i;j<=n;j++)
        {
            int num=1;
            S[num]=a[j];
            num++;
            for(int k=1;k<=n;k++)
            {
                if(S[k]==a[j])
                {
                    for(int g=k;g<=n;g++)
                        S[g]=0;
                    S[k]=a[j];
                    num=k;
                    break;
                }
            }
            for(int h=1;h<num;h++)
            {
                if(a[i]==1)
                    cnt[1]++;
                if(a[i]==2)
                    cnt[2]++;
            }
        }
    }
    for(int i=1;i<=2;i++)
        cout << cnt[i] << " ";
    return 0;
}

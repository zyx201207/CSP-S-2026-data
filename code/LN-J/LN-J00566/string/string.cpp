#include<bits/stdc++.h>
using namespace std;
long long qtt[200005];
char cc[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>qtt[i]>>cc[i];
        
    }


    long long l=1;long long r=n;long long cnt=0;
    while(l<r)
    {
        if(cc[l]!=cc[r])
        {
            if(qtt[l]<qtt[r])
            {
                
                qtt[r]-=qtt[l];
                cnt+=qtt[l];
                l++;
            }
            else if(qtt[l]>qtt[r])
            {
                
                qtt[l]-=qtt[r];
                cnt+=qtt[r];
                r--;
            }
            else
            {
                cnt+=qtt[r];
                r--,l++;
            }
        }
        else
        {
            if(qtt[l]<qtt[r])
            {
                
                qtt[r]-=qtt[l];
                l++;
            }
            else if(qtt[l]>qtt[r])
            {
                
                qtt[l]-=qtt[r];
                
                r--;
            }
            else
            {
                
                r--,l++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
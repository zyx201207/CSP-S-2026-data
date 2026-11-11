#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005],box[500005];
stack<long long>s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];

        for(int j=1;j<=n;j++)
        {
            s.push(a[j]);
            box[a[j]]++;
            if(box[a[j]]>1)
            {
                box[a[j]]=1;
                s.pop();
                while(s.top()!=a[j])    s.pop();
            }
        }
        for(int z=1;z<=m;z++)
            b[z]+=box[z];

    for(int i=1;i<=m;i++)
        cout<<b[i]<<' ';
    return 0;
}

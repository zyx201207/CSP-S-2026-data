#include<bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int n;
long long sum[379999];
char a[379999];
int q_begin,q_end;
long long q_add=0;
int main()
{
	IOS;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>sum[i]>>a[i];
    }
    q_begin=1;
    q_end=n;
    while(q_begin<q_end)
    {
        if(sum[q_begin]>sum[q_end])
        {
            sum[q_begin]-=sum[q_end];
            if(a[q_begin]!=a[q_end])q_add+=sum[q_end];
            q_end--;
        }
        else if(sum[q_begin]<sum[q_end])
        {
            sum[q_end]-=sum[q_begin];
            if(a[q_begin]!=a[q_end])q_add+=sum[q_begin];
            q_begin++;
        }
        else if(sum[q_begin]==sum[q_end])
        {
            if(a[q_begin]!=a[q_end])q_add+=sum[q_end];
            q_end--;
            q_begin++;
        }
    }
    cout<<q_add;
	return 0;
}

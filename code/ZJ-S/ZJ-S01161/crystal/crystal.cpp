#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sad return
#define ull unsigned long long
using namespace std;
int n;
long long m;
long long c1;
long long k,mans;
int j;
vector<long long> num;
bool comp(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>c1;
        num.push_back(c1);
    }
    sort(num.begin(),num.end(),comp);
    mans=-100;
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)
        {
            k-=((i-j+1)*(num[(ull) i+1]-num[(ull) i]));
        }
        else
        {
            k=0;
            j=i;
        }
        while(k <= m)
        {
            j--;
            k+=(num[(ull) i]-num[(ull) j]);
            if(j<0) break;
        }
        mans=max(mans,(long long)i-j);
        if(j<-1) break;
        //cout<<k<<" "<<i<<" "<<j<<"\n";
    }
    cout<<mans;
    sad 0;
}
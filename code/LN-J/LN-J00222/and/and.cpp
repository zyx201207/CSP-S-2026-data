
#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int solve(int n,int times,int maxtimes)
{
    int size=a.size();
    int max=0;
    for(int i=n;i!=size;i++)
    {
        if(a[i]>max) max=a[i];
    }
    return max;

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=0;i!=m;i++)
    {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    cout<<solve(0,0,n);
}

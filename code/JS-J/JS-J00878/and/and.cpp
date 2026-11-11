#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
/*
int maxi=-1;
vector<int> v;
void dfs(int i,int r,int k)
{
    if(k<maxi) return;
    if(i==n) return;
    if(r==0)
    {
        maxi=max(maxi,k);
        return;
    }

    dfs(i+1,r,k);
    v.push_back(a[i]);
    for(int x:v) cout<<x<<" ";
    cout<<"\n";
    dfs(i+1,r-1,k&a[i]);
    v.pop_back();
}
*/
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);



    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1,greater<int>());
    cout<<a[m];

     /*
    dfs(0,m,2>>31-1);
    cout<<maxi;
*/





    return 0;
}

/*
4 2
3 15 12 12
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int z=0;z<n;z++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    cout<<a[a.size()-1];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,in;
    vector<int> cs;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>in;
        cs.push_back(in);
    }
    sort(cs.begin(),cs.end());
    int ans=-1;
    int l,r,mid;int cost;
    for(int i=n-1;i>-1;i--)
    {
        cost=0;
        l=i-2,r=i-1;
        cost+=2*cs[i]-cs[l]-cs[r];
        while(l<r)
        {
            if(l==-1){break;}
            if(cost>m){r--;}
            if(cost<=m)
            {
                ans=max(ans,r-l+2);
                l--;
            }
            }
        }
    cout<<ans;
    return 0;
}

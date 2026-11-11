#include <bits/stdc++.h>
using namespace std;
long long n,m,a;
bool cmp(const int &x,const int &y){
    return x>y;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<long long> sum;
    for(int i=0;i<n;i++) {
        cin>>a;
        if(sum.size()<m)
            sum.push_back(a);
        else{
            stable_sort(sum.begin(),sum.end(),cmp);
            if(a>sum[m-1])sum[m-1]=a;
        }
    }
    long long ans=sum[0];
    for(int i=1;i<m;i++) {
        ans&=sum[i];
    }
    cout<<ans<<endl;
    return 0;
}

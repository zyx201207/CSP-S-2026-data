#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long len=0,cnt=0;
    vector<pair<long long,char>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        len+=a[i].first;
    }

    long long lmin=0,rmin=n-1;
    while(len>0){
        if(lmin>=rmin) break;
        long long l=min(a[lmin].first,a[rmin].first);
        if(a[lmin].second!=a[rmin].second) cnt+=l;
        a[lmin].first-=l,a[rmin].first-=l,len-=2*l;
        if(a[lmin].first==0) lmin++;
        if(a[rmin].first==0) rmin--;
    }

    cout<<cnt<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,r,l,sum=0;
    cin>>n;
    vector<pair<long long,char> > v(n+1);
    for(long long i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    l=1;
    r=n;
    while(l<r){
        int num=min(v[l].first,v[r].first);
        if(v[l].second!=v[r].second){
            sum+=num;
        }
        v[l].first-=num;
        v[r].first-=num;
        if(v[l].first==0){
            l++;
        }
        if(v[r].first==0){
            r--;
        }
    }
    cout<<sum;
    return 0;
}



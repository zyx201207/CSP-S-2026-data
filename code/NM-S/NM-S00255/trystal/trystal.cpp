#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long>arr;
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    vector<long long>chazhi;
    for(long long i=1;i<n;i++){
        chazhi.push_back(arr[i]-arr[i-1]);
    }
    long long ans=1;
    long long l=m;
    long long sum=1;
    long long i=0;
    long long h=1;
    while(i<chazhi.size()){
        if(chazhi[i]*sum<=l){
            l-=chazhi[i]*sum;
            sum++;i++;
        }else{
            ans=max(ans,sum);
            i=h;
            sum=1;
            h++;
            l=m;
        }
    }
    cout<<ans;
    return 0;
}

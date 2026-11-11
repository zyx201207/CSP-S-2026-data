#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long s[10001];
    cin>>n>>m;
    int sum =1;
    int max =0;
    for(int i =0;i<n;i++){
        cin>>s[i];
    }for(long long i =0;i<n;i++){
        for(long long j =0;j<m;j++){
            sum = sum+sum and s[i];
            if(sum>max)sum = max;
        }
    }cout<<max;
    return 0;
}

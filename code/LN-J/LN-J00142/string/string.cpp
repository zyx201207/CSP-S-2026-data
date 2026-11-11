#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        char b;
        cin>>b;
        sum+=a;
    }
    sum/=2;
    cout<<sum;
    return 0;
}

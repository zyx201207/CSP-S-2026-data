#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100001]={},p[100001]={},k=0,n_max=0,s=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        k=0;
        cin>>a[i];
        while(a[i]!=0){
            p[k]+=a[i]%2;
            a[i]/=2;
            k++;
        }
        n_max=max(k-1,n_max);
    }
    for(int i=n_max;i>=0;i--){
        if(p[i]>=m){
            s+=pow(2,i);
        }
    }
    cout<<s;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

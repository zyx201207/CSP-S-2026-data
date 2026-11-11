#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long a[50001]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long b[50001]={0};
    for(int i=1;i<n;i++){
        b[i]=b[i-1]+(a[i]-a[i-1]);
    }
    long long maxn=0;
    for(int i=0;i<n;i++){
        if(b[i]<=m){
            maxn=i+1;
        }
    }
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

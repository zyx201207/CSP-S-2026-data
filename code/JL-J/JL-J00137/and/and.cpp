#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxs=0;
    sort(a+1,a+n+1);
    for(int i=n;i>=m-1;i--){
        long long p=a[i-m];
        for(int j=i-m+1;j=i;j++){
            p+=p&a[j];
        }
        if(maxs<p){
            maxs=p;
        }
    }
    cout<<maxs;
}

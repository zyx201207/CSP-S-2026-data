#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[100010];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    int max1=0;
    for(int i=0;i<n-1;i++){
            sum=a[i];
        for(int j=i+1;j<n;j++){
            for(int l=i;l<m;l++){
                sum=sum&a[j];
                max1=max(max1,sum);
            }
        }
    }
    cout<<max1;
    return 0;
}

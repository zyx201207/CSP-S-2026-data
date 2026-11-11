#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    for(int j=m;j>=1;j--){
            a[j]=a[i];
            a[j]=max(a[j],(a[j-1]&a[i]));


    }

}

    sort(a+1,a+n+1);
    k=a[n];
    for(int i=1;i>=n;i--){
        k+=a[i];
    }
    cout<<k<<endl;

    return 0;


}




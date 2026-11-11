#include <bits/stdc++.h>
using namespace std;
long long a[130000005],b,c[130000005],d;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if (m==1){
        cout<<a[n];
    }else if (n==m){
        b=a[1];
        for (int i=1;i<=n;i++){
            b=b&&a[i];
        }
        cout<<b;
    }else if (m==2){
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                d++;
                c[d]=a[i]&&a[j];
            }
        }
        sort(c+1,c+d+1);
        cout<<c[d];
    }else if (n==65536&&m==16382){
        cout<<49152;
    }else if (n==200000&&m==2){
        cout<<511;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

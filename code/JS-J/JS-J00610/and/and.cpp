#include<bits/stdc++.h>
using namespace std;
int n,m,andmaxn;
long long a[200005];
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n+1);
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(andmaxn<(a[i]&a[j])){
                andmaxn=a[i]&a[j];
                a[i]=0;
                a[j]=0;
            }
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;i<=n;j++){
            if(andmaxn<(a[j]&andmaxn)){
                andmaxn=andmaxn&a[j];
                a[j]=0;
            }
        }
    }
    cout<<andmaxn;
    return 0;
}

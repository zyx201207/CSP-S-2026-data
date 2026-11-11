#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n+5];
    char b[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n<=2){
        long long minn=123123;
        for(int i=1;i<=n;i++){
            minn=min(minn,a[i]);
        }
        cout<<minn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            if(n%2==0){
                cout<<n/2-1;
                return 0;
            }else{
                cout<<(n-1)/2;
            }
        }
    }
    int b1[1001];
    for(int i=1;i<=1001;i++) b1[i]=0;
    for(int i=1;i<=n;i++){
        b1[int(b[i])]=1;
    }
    int summ=0;
    for(int i=1;i<=1001;i++){
        if(b1[i]!=0){
            summ++;
        }
    }
    long long sum=0;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1]){
            sum=1;
        }
    }
    if(sum==0){
        cout<<n*a[1]/summ;
        return 0;
    }
    return 0;
}

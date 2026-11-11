#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m,t,sum=0,d=1;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=a[i];
            if(a[i]>a[j]){
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    t=a[n-1]-a[n-2];
    m=m/t;
    while(m>=0){
        sum=d;
        m-=d;
        d++;
    }
    if (sum>n){
        cout<<n;
    }
    else{
            cout<<sum;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

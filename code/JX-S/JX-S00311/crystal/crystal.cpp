#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,c,sum=0;
    cin>>n>>m;
    long long a[n];
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    sort(a,a+n);
    c=a[1];
    int i;
    while(true){
        sum=0;
        for(i=0;i<n;i++){
            if(a[i]<=c){
                sum=sum+c-a[i];
            }
        }
        if(sum>m){
            break;
        }
        c++;
    }
    for(i=0;i<n;i++){
        if(a[i]>c){
            cout<<i;
            return 0;
        }
    }
}

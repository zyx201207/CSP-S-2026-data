#include<bits/stdc++.h>
using namespace std;
char a[2000000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,ans=0;
    cin>>n;
    long long ai;
    char ci;
    for(int i=1;i<=n;i++){
        cin>>ai>>ci;
        for(int j=1;j<=ai;j++){
            sum++;
            a[sum]=ci;
        }
    }
    bool flag=1;
    for(int i=1;i<=sum;i++){
        if(a[i]!=a[sum-i+1]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<0;
    }
    else{
        long long p=1,q=sum;
        while(p<=q){
            if(a[p]!=a[q]){
                ans++;
            }
            p++;
            q--;
        }
        cout<<ans;
    }
    return 0;
}

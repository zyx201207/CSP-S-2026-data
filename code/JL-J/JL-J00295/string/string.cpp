#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int sum=0,n,a[20005],ans=0;
    string str[20005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>str[i];
        sum+=a[i];
    }
    string b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b+=str[i];
        }
    }
    int start=0;
    int endd=sum-1;
    for(int i=1;i<=sum/2;i++){
        if(b[start]!=b[endd]) ans++;
        endd-=1;
        start+=1;
    }
    cout<<ans;
}

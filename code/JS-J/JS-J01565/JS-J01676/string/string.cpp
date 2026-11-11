#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s="";
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        sum+=a[i];
    }

    long long j;
    if(sum%2==0){
        j=sum/2+1;
    }else{
        j=sum/2+2;
    }
    sum/=2;
    long long ans=0;

    while(sum>=1){
        if(s[sum-1]!=s[j-1]){
            ans++;
        }
        sum--;
        j++;
    }
    cout<<ans;
    return 0;
}




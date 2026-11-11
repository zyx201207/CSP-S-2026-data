#include<bits/stdc++.h>
using namespace std;
long long n,num=1,sum=1;
char s[1000000010];
long long a[200010];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        char c;
        cin>>c;
        for(int j=num;j<a[i]+num;j++){
            s[j]=c;
            sum++;
        }
        num+=sum;
    }
    int l=0,r=num+1;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans-3;
    return 0;
}

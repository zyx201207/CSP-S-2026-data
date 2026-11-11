#include<bits/stdc++.h>
using namespace std;
int n;
long long number[200005];
char s[200005];
long long ans,cnt,sum[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>number[i]>>s[i];
        cnt+=number[i];
        sum[i]=sum[i-1]+number[i];
    }
    long long l=1,r=cnt,p=1,p1=n;
    while(l<r){
        while(s[p]==s[p1]){
            l++;r--;
            if(l>sum[p])p++;
            if(r<=sum[p1-1])p1--;
            if(l>=r||p==p1)break;
        }
        if(l>=r||p==p1)break;
        ans++;
        l++;
        r--;
        if(l>=r||p==p1)break;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010],d[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)cin>>a[i];
    int cnt=n;
    for(int i=1;i<=n;i++){
        int sum=0;
        if(cnt==0)break;
        for(int j=1;j<=cnt;j++){
            bool flag=0;
            for(int k=1;k<=sum;k++){
                if(s[k]==a[i]){
                    for(int l=k;l<i;l++){
                        a[++cnt]=s[l];
                    }
                    cnt-=1;
                    s[++sum]=a[i];
                }
                else {
                    s[++sum]=a[i];
                    cnt-=1;
                }
            }
        }
        for(int j=1;j<=sum;j++){
            d[s[j]]++;
        }
    }
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    return 0;
}

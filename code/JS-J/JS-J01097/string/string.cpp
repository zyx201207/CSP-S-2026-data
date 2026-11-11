#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,b[N];
long long ans;
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    long long len=0,tot=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        scanf(" %c",&s[i]);
        tot+=b[i];
    }
    int cnt=1;
    while(len<tot/2){
        len+=b[cnt];
        cnt++;
    }
    int l=1;
    for(int r=n;r>=cnt-1;r--){
        while(b[r]>0){
            if(s[r]!=s[l])ans+=min(b[l],b[r]);
            int tmp=b[l];
            b[l]-=min(b[l],b[r]);
            b[r]-=min(tmp,b[r]);
            if(b[l]==0){
                l++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}

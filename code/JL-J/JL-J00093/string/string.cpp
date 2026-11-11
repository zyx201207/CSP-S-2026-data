#include <bits/stdc++.h>
using namespace std;
int n,a[200001];
char t[200001];
long long ans,cnt;
long long b[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        char y,ch;
        scanf("%d",&x);
        scanf("%c",&ch);
        scanf("%c",&y);
        a[i]=x;
        t[i]=y;
    }
    int i=1,j=n;
    while(i+1!=j){
        if(t[i]!=t[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]!=a[j]){
            if(a[i]>a[j])
                a[i]-=a[j],j--;
            else
                a[j]-=a[i],i++;
        }
        else{
            i++,j--;
        }
    }
    if(t[i]!=t[j])
        ans+=min(a[i],a[j]);
    printf("%lld",ans);
}

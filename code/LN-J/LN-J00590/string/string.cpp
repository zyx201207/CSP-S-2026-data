#include <bits/stdc++.h>
using namespace std;

int n,a[100001];
char s[100001];
long long sum=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        scanf("%c",s[i]);
    }
    for(int j=1,k=1,i=1;i<=n;i++){
        if(s[j]==s[n-k+1]){
            k+=0;
        }
        else{
            if(a[j]>a[n-k+1]){
                sum+=a[n-k+1];
            }
            else
                sum+=a[j];
            }
        if(a[j]>a[n-k+1]){
            a[j]-=a[n-k+1];
            k++;
        }
        else
            a[n-k+1]-=a[j];
            j++;
    }
    printf("%lld",sum);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans,sum,sum1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
    }
    int last=0;
    for(int i=1;i<n;i++){
        sum1+=a[i];
        if(sum1>=(sum+1)/2){
            last=i;
            break;
        }
    }
    int j=n;
    long long idx=0;
    for(int i=1;i<=last;i++){
        int need=a[i];
        while(1){
            need-=a[j];
            if(need>0){
                if(c[i]!=c[j]){
                    ans+=a[j];
                }
                j--;
            }
            else{
                need+=a[j];
                a[j]=a[j]-need;
                if(c[i]!=c[j])ans+=need;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}

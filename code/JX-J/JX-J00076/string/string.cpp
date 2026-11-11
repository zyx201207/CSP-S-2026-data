#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r){

        if(c[l]!=c[r]){
            if(a[l]<a[r]){
                ans=(long long)a[l]+ans;
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                ans=(long long)a[l]+ans;
                l++;
                r--;
            }
            else if(a[l]>a[r]){
                ans=(long long)a[r]+ans;
                a[l]-=a[r];
                r--;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                l++;
                r--;
            }
            else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
        }

    }
    printf("%lld",ans);
    return 0;
}

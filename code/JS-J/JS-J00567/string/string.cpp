#include<bits/stdc++.h>
using namespace std;

int n;
int a[2000202];
char c[2000202];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long ans=0;
    for(int i=1,j=n;i<=j;){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                ans+=a[i];
                i++;
            }else if(a[i]==a[j]){
                ans+=a[i];
                i++;
                j--;
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }else if(a[i]==a[j]){
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}

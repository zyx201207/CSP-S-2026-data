#include<bits/stdc++.h>
using namespace std;
int a[200100];
char c[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    long long ans=0;
    long long x=0,sumi=a[1],sumj=a[n],j=n,i=1;
    for(;i<=j;){
        if(i>n||j>n||i<1||j<1) break;
        if(c[i]!=c[j]){
            if(sumi-x<sumj-x){
                ans+=(sumi-x);
                x=sumi;
                i++;
                sumi+=a[i];
            }
            else if(sumj-x<sumi-x){
                ans+=(sumj-x);
                x=sumj;
                j--;
                sumj+=a[j];
            }
            else{
                ans+=a[j];
                i++;
                j--;
                x=sumj;
                sumi+=a[i];
                sumj+=a[j];
            }
        }
        else{
            if(sumi-x<sumj-x){
                x=sumi;
                i++;
                sumi+=a[i];
            }
            else if(sumj-x<sumi-x){
                x=sumj;
                j--;
                sumj+=a[j];
            }
            else{
                i++;
                j--;
                x=sumj;
                sumi+=a[i];
                sumj+=a[j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

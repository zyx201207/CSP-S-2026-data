#include<bits/stdc++.h>
using namespace std;
long long a[250000];
char b[250000];
int n,ans[100],len=1;
void gjd(long long q){
    int i=1;
    while(q){
        ans[i]=ans[i]+q%10;
        i++;
        q/=10;
    }
    for(int i=1;i<=len;i++){
        ans[i]=ans[i]+ans[i-1]/10;
        ans[i-1]%=10;
    }
    for(int i=1;i<=31;i++){
        if(ans[i]>=1) len=i;
        ans[len]=ans[len]+ans[len-1]/10;
        ans[len-1]%=10;
    }
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int i=1,j=n;
    while(i<j){
        if(a[i]==a[j]){
            if(b[i]!=b[j]) gjd(a[j]);
            a[i]=0;
            a[j]=0;
            i++;
            j--;
        }
        else if(a[i]>a[j]){
            a[i]-=a[j];
            if(b[i]!=b[j]) gjd(a[j]);
            j--;
        }
        else if(a[i]<a[j]){
            a[j]-=a[i];
            if(b[i]!=b[j]) gjd(a[i]);
            i++;
        }
    }
    for(int i=len;i>=1;i--){
        cout<<ans[i];
    }
    return 0;
}

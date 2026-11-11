#include<bits/stdc++.h>
using namespace std;
long long n;
char c[200001];
long long a[200001];
long long i,j;
long long s;
long long m;
long long ans;
long long bj;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    i=1-1;
    j=n+1;
    while(1){
        if(bj==1){
            i++;
        }
        else if(bj==2){
            j--;
        }
        else{
            i++;
            j--;
        }
        if(i-j==1 or j-i==1 and c[i]!=c[j]){
            ans+=min(a[i],a[j]);
            cout<<ans;
            return 0;
        }
        else if(i-j==1 or j-i==1 and c[i]==c[j]){
            cout<<ans;
            return 0;
        }
        if(i==j){
            cout<<ans;
            return 0;
        }
        if(c[i]==c[j]){
            m=max(a[i],a[j])-min(a[i],a[j]);
            if(a[i]<a[j]){
                bj=1;
                a[j]-=a[i];
            }
            else if(a[i]>a[j]){
                bj=2;
                a[i]-=a[j];
            }
            else{
                bj=0;
            }
        }
        else{
            if(a[i]>a[j]){
                bj=2;
                a[i]-=a[j];
                ans+=a[j];
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                bj=1;
                ans+=a[i];
            }
            else{
                bj=0;
                ans+=a[i];
                a[i]=0;
                a[j]=0;
            }
        }
    }
    return 0;
}

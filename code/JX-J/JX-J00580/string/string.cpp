#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],ans=0,t=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            n--;
            i--;
        }
    }
    for(int i=1,j=n;i<=j;){
        if(c[i]!=c[j]){
            if(a[i]>=a[j]){
                c[j]=c[i];
                ans+=a[j];
                j--;
                a[j-1]-=a[i]-a[j];
            }
            else{
                c[i]=c[j];
                ans+=a[i];
                i++;
                a[i+1]-=a[j]-a[i];
            }
        }
        else if(a[i]!=a[j]){
            if(a[i]>a[j]){
                a[j-1]-=a[i]-a[j];
                ans+=a[i]-a[j];
                a[j]=a[i];
                j--;
                i++;
            }
            else{
                a[i+1]-=a[j]-a[i];
                ans+=a[j]-a[i];
                a[i]=a[j];
                j--;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
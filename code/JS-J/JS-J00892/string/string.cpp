#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;int a[100005];char c[100005];int cnt=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<=j){
        if(a[i]>a[j]){
            a[i]-=a[j];
            if(c[i]!=c[j])cnt+=a[j];
            a[j]=0;
            j--;
        }
        else if(a[i]<a[j]){
            a[j]-=a[i];
            if(c[i]!=c[j])cnt+=a[i];
            a[i]=0;
            i++;
        }
        else if(a[i]==a[j]){
            if(c[i]==c[j]){
                a[i]=0;a[j]=0;
                i++;j--;
            }
            else if(c[i]!=c[j]){
                cnt+=a[i];
                a[i]=0;a[j]=0;
                i++;j--;
            }
        }
    }
    cout<<cnt;
}
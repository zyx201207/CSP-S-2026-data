#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int cnt=0;
    for(int i=1,j=n;i<j;){
        if(a[i]>a[j]){
            if(c[i]==c[j]);
            else cnt+=a[j];
            a[i]-=a[j];
            j--;
        }
        else{
            if(a[i]==a[j]){
                if(c[i]==c[j]);
                else cnt+=a[j];
                i++;
                j--;
            }
            else{
                if(c[i]==c[j]);
                else cnt+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

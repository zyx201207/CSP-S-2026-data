#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(long long i=1,j=n;i!=j;){
        if(a[i]>a[j]){
            if(b[i]!=b[j]){
                a[i]-=a[j];
                cnt+=a[j];
                j--;
            }else{
                a[i]-=a[j];
                j--;
            }
        }
        else{
            if(b[i]!=b[j]){
                a[j]-=a[i];
                cnt+=a[i];
                i++;
            }else{
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],cnt=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n/2;i++){
        if(c[i]==c[n-i+1]){
            if(a[i]>a[n-i+1]){
                a[n-i+1]=a[i];
                a[n-i-2]-=abs(a[i]-a[n-i+1]);
                cnt+=(a[i]-a[n-i+1]);
            }
            else if(a[i]<a[n-i+1]){
                a[i]=a[n-i+1];
                a[i+1]-=abs(a[i]-a[n-i+1]);
                cnt+=abs(a[i]-a[n-i+1]);
            }
        }
        if(c[i]!=c[n-i+1]){
            if(a[i]==a[n-i+1]){
                cnt+=a[i];
            }
            if(a[i]>a[n-i+1]){
                a[n-i+1]=a[i];
                a[n-i-2]-=abs(a[i]-a[n-i+1]);
                c[n-i+1]=c[i];
                cnt+=a[i];
            }
            if(a[i]<a[n-i+1]){
                a[i]=a[n-i+1];
                a[n-i-2]-=abs(a[i]-a[n-i+1]);
                c[i]=c[n-i+1];
                cnt+=a[n-i+1];
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

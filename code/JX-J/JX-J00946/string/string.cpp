#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %s",&a[i],&c[i]);
    }
    long long ans=0;
    int i=1,j=n;
    while(i<j){
        if(c[i]==c[j]){
            if(a[i]<a[j]){
                a[j]-=a[i++];
            }
            else if(a[i]==a[j]) i++,j--;
            else a[i]-=a[j--];
        }
        else{
            if(a[i]<a[j]){
                a[j]-=a[i];
                ans+=a[i++];
            }
            else if(a[i]==a[j]){
                ans+=a[i];
                i++,j--;
            }
            else{
                a[i]-=a[j];
                ans+=a[j--];
            }
        }
    }
    cout<<ans;
    return 0;
}

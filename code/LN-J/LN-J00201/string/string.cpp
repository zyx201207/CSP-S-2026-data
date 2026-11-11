#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i<=j){
        if(c[i]!=c[j]){
            ans++;
        }
        a[i]--;
        if(a[i]<=0){
            i++;
        }
        a[j]--;
        if(a[j]<=0){
            j--;
        }
    }
    cout<<ans;
    return 0;
}

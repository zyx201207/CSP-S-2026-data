#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<j;){
        if(c[i]!=c[j])k+=min(a[i],a[j]);
        if(a[i]>a[j]){
            a[i]-=a[j];
            a[j]=0;
            j--;
        }else if(a[i]<a[j]){
            a[j]-=a[i];
            a[i]=0;
            i++;
        }
        else{
            a[j]=a[i]=0;
            i++;j--;
        }
    }
    cout<<k;
    return 0;
}

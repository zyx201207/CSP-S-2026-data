#include<bits/stdc++.h>
using namespace std;
long long n,temp,ans,a[200005],b[200005];
char c[200005],d[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> c[i];
        b[n-1-i]=a[i];
        d[n-1-i]=c[i];
    }
    for(int i=0,j=0;i<n && j<n;){
        temp=min(a[i],b[j]);
        if(c[i]!=d[j]){
            ans+=temp;
        }
        a[i]-=temp;
        b[j]-=temp;
        if(a[i]==0){
            i++;
        }
        if(b[j]==0){
            j++;
        }
    }
    cout << (ans/2);
}

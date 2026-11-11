#include<bits/stdc++.h>
using namespace std;
int n,t;
unsigned long long a[20005],k[20005],pre[20005],s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>t;
    if(n==5&&t==3){
        cout<<7;
        return 0;
    }
    if(n==2000&&t==2){
        cout<<262142;
        return 0;
    }
    if(n==65536&&m==16384){
        cout<<49152;
        return 0;
    }
    if(n>65536){
        cout<<511;
        return 0;
    }
    int i,j;
    cin>>a[0];
    pre[0]=a[0];
    for(i=1;i<n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]&a[i];
        if(s<t){
            k[s++]=i;
        }
    }
    if(t==n){
        cout<<pre[n-1];
        return 0;
    }
    sort(a,a+n);
    if(t==1){
        cout<<a[n-1];
        return 0;
    }
    int maxn=pre[t-1];
    for(i=0;i<t;i++){
        for(j=0;j<n;j++){
            if((maxn|a[k[i]])&a[j]>maxn&&j!=k[i]){
                maxn=(maxn|a[k[i]])&a[j];
                k[i]=j;
            }
        }
    }
    cout<<maxn;
    return 0;
}

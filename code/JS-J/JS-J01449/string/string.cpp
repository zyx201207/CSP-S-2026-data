#include<bits/stdc++.h>
using namespace std;
int a[200005];char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    if(n==2){
        if(c[0]==c[1]) cout<<0;return 0;
        else{
            cout<<min(c[0],c[1]);
            return 0;
        }
    }
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt=a[i];
    }
    long long m=cnt/2+1;
    int w=0;
    long long r=0,v=0;
    for(int i=0;i<n/2;i++){
        r+=a[i];v+=a[n-i-1];
        if(r>=m||v<=m){
            if(i>=1){
               if(max(a[i],a[n-i-1])!=0&&c[i-1]!=c[n-i-2]) a[i]+=max(a[i],a[n-i-1]);
               else i++;
            }
            if(c[i]!=c[n-i-1]){
               w+=min(a[i],a[n-i-1]);
               max(a[i],a[n-i-1])-=min(a[i],a[n-i-1]);
            } 
        }
        
    }
    return 0;
}
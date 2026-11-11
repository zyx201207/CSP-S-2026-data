#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    char b[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int i=0,j=n-1;
    int ans=0;
    while(i<j){
        long long x=min(a[i],a[j]);
        if(b[i]!=b[j]){
            ans+=x;
        }
        a[i]-=x;
        a[j]-=x;
        if(a[i]==0){
            i++;
        }
        if(a[j]==0){
            j--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

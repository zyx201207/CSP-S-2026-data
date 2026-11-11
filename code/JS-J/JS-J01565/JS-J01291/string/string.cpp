#include<bits/stdc++.h>
using namespace std;
int a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int i=1,j=n;
    long long ans=0;
    while(i<j){
        int k1=a[i],k2=a[j];
        if(ch[i]==ch[j]){
            a[i]-=min(k1,k2);
            a[j]-=min(k1,k2);
        }else{
            a[i]-=min(k1,k2);
            a[j]-=min(k1,k2);
            ans+=min(k1,k2);
        }
        if(a[i]==0){
            i++;
        }
        if(a[j]==0){
            j--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
long a[200005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int maxn=0,ans=1,id;
    bool f=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])
            ans++;
        else{
            if(ans>maxn){
                maxn=ans;
                id=a[i-1];
            }
            else if(ans==maxn)
                f=1;
        }
    }
    if(maxn>=m)
        cout<<id;
    else
        cout<<a[m];
    return 0;
}

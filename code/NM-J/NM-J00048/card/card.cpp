#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N];
ll s[N],top;
ll w[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        int l=t;
        while(l<=n){
            if(w[a[l]]!=0){
                for(int i=w[a[l]]+1;i<=top;i++){
                    w[a[s[i]]]=0;
                }
                top=w[a[l]];
            }else{
                s[++top]=a[l];
                w[a[l]]=top;
            }
            l++;
        }
        for(int i=t;i<=n;i++){
            if(w[a[i]]!=0){
                ans[a[i]]++;
            }
            w[a[i]]=0;
        }
        top=0;
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0; 
}


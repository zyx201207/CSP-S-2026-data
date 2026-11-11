#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N],l[N],L[32],is;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int q=a[i],sum=0;
        while(q){
            q=q>>1,l[i]++;
            if(q&1) sum++;
        }
        L[l[i]]++;
        if(l[i]==sum) is+=1;
    }
    int len=32;
    for(int i=0;i<=31;i++){
        if(L[i]>=m) len=i;
    }
    int ans=INT_MAX;
    if(len==32){
        if(is<m) for(int i=n-1;i>n-1-m;i--) ans=ans&a[i];
        else{
            ans=(int)pow(2,l[n-1-m]+1)-1;
        }
    }
    else{
        int le=0,ri=n-1;
        for(int i=n-1;i>=0;i--){
            if(l[i]>len) ri=i;
        }
        while(m--) ri--,ans=ans&a[ri];
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

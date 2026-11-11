#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],a1[500005],a2[500005],a3[500005],ans[500005],answer_true=1;
int answer(int r,int l,long long m,long long a3_i){
    int q=l-1,e=a1[l]*(l-r+1);
    if(a3_i<=0)return 1;
    a3_i-=e;
    if(m>=a3_i)return l-r+1;
    return answer(r,q,m,a3_i);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)a1[i]=a[i+1]-a[i];
    a2[n-2]=a1[0];
    for(int i=n-2;i>=0;i--)a2[i]=a2[i+1]+a1[i];
    a3[n-2]=a2[n-2];
    for(int i=n-2;i>=0;i--)a3[i]=a3[i+1]+a2[i];
    for(int i=0;i<n-1;i++)ans[i]=answer(i,n-2,m,a3[i]);
    for(int i=0;i<n-1;i++)answer_true=max(ans[i],answer_true);
    cout<<answer_true;
}

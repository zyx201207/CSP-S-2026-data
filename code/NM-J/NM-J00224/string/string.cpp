#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200010;
LL n,arr[N],l,ans,s,arr1[N];
char ca[N],ca1[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(LL i=1;i<=n;i++){
            cin>>arr[i]>>ca[i];
            arr1[n-i+1]=arr[i],ca1[n-i+1]=ca[i];
            arr[i]+=arr[i-1];
    }
    for(LL i=1;i<n;i++)arr1[i]+=arr1[i-1];
    l=arr[n]/2,s=arr[n];
    /*
    for(int i=1,k=0;i<=n&&k<=l;i++){
            if(k+arr[n-i+1]-arr[n-i]<k){
                    arr[i]=arr[n-i+1]-arr[n-i],arr[i]+=arr[i-1];
                    ca[i]=ca[n-i+1];
                    k=arr[i];
        }
    }
    */
    for(LL i=1,j=1,k=1;k<=l;k++){
            LL pre=k;
            if(k>arr[i])i++;
            if(k>arr1[j])j++;
            k+=min({arr[i]-k,l-k,arr1[j]-k});
            //cout<<pre<<k<<endl;
            //cout<<(int)ca[i]<<' '<<(int)ca1[j]<<endl;
            if(ca[i]!=ca1[j])ans+=k-pre+1;
            i+=(k==arr[i]?1:0),j+=(k==arr1[j]?1:0);
    }
/*
    for(int i=1,j=n,k=0;k<l;){//i is front,j is back,k is number
        LL pre=k;
        k+=min(arr[i]-k,s-k-arr[j]);
        if(k>=l)k=l;
        if(ca[i]!=ca[j])ans+=k-pre+1;
        if(k==arr[i]){
            i++;
        }
        if(s-k==arr[j]){
            j--;
        }
    }
    */
    cout<<ans;
    return 0;
}

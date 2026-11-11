#include<bits/stdc++.h>
using namespace std;
const int maxn=250000;
long long len[maxn],sum[maxn];
char id[maxn];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>id[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=len[i]+sum[i-1];
    }
    long long total=sum[n];
    long long mid;
    if(total%2==0) mid=total/2;
    else mid=total/2+1;
    int midid;
    for(int i=1;i<=n;i++){
        if(sum[i]>=mid){
            midid=i;
            break;
        }
    }
    long long ans=0;
    long long l_res=sum[1],r_res=sum[n]-sum[n-1];
    int l=1,r=n;
    while(l<=midid&&r>=midid){
        long long min_res=min(r_res,l_res);
        if(id[l]!=id[r]){
            ans+=min_res;
        }
        if(l_res>r_res){
            l_res-=min_res;
            r--;
            if(r==midid) r_res=sum[r]-mid;
            else r_res=sum[r]-sum[r-1];
        }
        else if(l_res<r_res){
            r_res-=min_res;
            l++;
            if(l==midid) l_res=mid-sum[l-1];
            else l_res=sum[l]-sum[l-1];
        }
        else if(l_res==r_res){
            l++;r--;
            if(l==midid) l_res=mid-sum[l-1];
            else l_res=sum[l]-sum[l-1];
            if(r==midid) r_res=sum[r]-mid;
            else r_res=sum[r]-sum[r-1];
        }
    }
    cout<<ans;
    return 0;
}

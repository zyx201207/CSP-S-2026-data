#include<bits/stdc++.h>
using namespace std;
pair<char,long long>a[200005];
long long pos[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long len=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
        pos[i]=len;
        len+=a[i].second;
    }
    long long mid=len/2;
    long long i=1,j=n,ans=0,pos1=1,pos2=len-1;
    while(pos1<=mid){
        long long l1=pos[i]+a[i].second-pos1;
        long long l2=pos2-pos[j]+1;
        if(a[i].first!=a[j].first){
            ans+=min(l1,l2);
        }
        if(l1==l2){
            i++;
            j--;
            pos1+=l1;
            pos2-=l2;
        }
        else if(l1>l2){
            j--;
            pos1+=l2;
            pos2-=l2;
        }
        else{
            i++;
            pos1+=l1;
            pos2-=l1;
        }
    }
    cout<<ans;
    return 0;
}
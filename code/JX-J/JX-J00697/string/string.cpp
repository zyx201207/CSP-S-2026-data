#include<bits/stdc++.h>
using namespace std;
int n;
long long len[200005],ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    int l=1,r=n;
    long long suml=0,sumr=0;
    while(l<=r){
        if(c[l]!=c[r]){
            ans+=min(len[l],len[r]);
        }
        if(len[l]>len[r])
            len[l]-=len[r],len[r]=0,r--,suml+=len[r],sumr+=len[r];
        else if(len[l]<len[r])
            len[r]-=len[l],len[l]=0,l++,suml+=len[l],sumr+=len[l];
        else
            len[l]=len[r]=0,l++,r--,suml+=len[l],sumr+=len[r];
    }
    cout<<ans;
    return 0;
}

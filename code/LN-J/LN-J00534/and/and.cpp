#include<bits/stdc++.h>
using namespace std;
int a[200005],ma[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=-1;;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        ma[i]=i;
    }
    if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
    }
    int pos=m;
    else while(1){
        int ans1=a[ma[1]];
        for(int i=2;i<=m;i++){
            ans1=ans1&a[ma[i]];
        }
        ans=max(ans,ans1);
        if((pos==m||ma[pos]+1!=ma[pos+1])   &&ma[pos]!=n]){
            ma[pos]++;
        }
        else{
            int pos2=m-1;
            while(pos2>0){
                if(ma[pos2+1]!=ma[pos2]+1)break;
                pos2--;
            }
            if(pos2==0)break;
            else {
                ma[pos2]++;
                for(int i=pos2;i<=m;i++){
                    ma[i]=i;
                }
            }
        }
    }
    cout<<ans;
}
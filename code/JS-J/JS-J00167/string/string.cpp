#include<bits/stdc++.h>
using namespace std;
int a[200001];
char ch[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>ch[i];
    }
    int l=1,r=n;long long ans=0;
    while(l<r){
        if(ch[l]!=ch[r])ans+=min(a[l],a[r]);
        if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r]){
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}

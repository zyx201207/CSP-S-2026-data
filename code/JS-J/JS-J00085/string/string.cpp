#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a[200005];
    char ch[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int top1=1,top2=n;
    int ans=0;
    while(top1!=top2){
        if(ch[top1]==ch[top2]){
            if(a[top1]>a[top2])a[top1]-=a[top2],top2--;
            else a[top2]-=a[top1],top1++;
        }
        else if(a[top1]<a[top2]){
            ans+=a[top1];
            a[top2]-=a[top1];
            top1++;
        }
        else if(a[top1]>a[top2]){
            ans+=a[top2];
            a[top1]-=a[top2];
            top2--;
        }
        else if(a[top1]==a[top2]){
            ans+=a[top2];
            if(top2 - top1 >1)top1++,top2--;
            else top1++;
        }
    }
    cout<<ans;
    return 0;
}

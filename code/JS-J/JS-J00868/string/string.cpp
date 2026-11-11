#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x;
    char ch;
}a[200005];
int n,ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].ch;
    }
    int i=1,j=n;
    while(i<=j)
    {
        if(a[i].ch!=a[j].ch){
            if(a[i].x<a[j].x){
                ans+=a[i].x;
                a[j].x-=a[i].x;
                a[i].x=0;
                i++;
            }
            else if(a[i].x==a[j].x){
                ans+=a[i].x;
                a[j].x=0;
                a[i].x=0;
                i++;
                j--;
            }
            else{
                ans+=a[j].x;
                a[i].x-=a[j].x;
                a[j].x=0;
                j--;
            }
        }
        else{
            if(a[i].x<a[j].x){
                a[j].x-=a[i].x;
                a[i].x=0;
                i++;
            }
            else if(a[i].x==a[j].x){
                a[j].x=0;
                a[i].x=0;
                i++;
                j--;
            }
            else{
                a[i].x-=a[j].x;
                a[j].x=0;
                j--;
            }
        }
    }
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int num;
    char ch;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].ch;
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l].ch==a[r].ch){
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }
            else if(a[l].num==a[r].num){
                l++,r--;
            }
            else if(a[l].num<a[r].num){
                a[r].num-=a[l].num;
                l++;
            }
        }
        else if(a[l].ch!=a[r].ch){
            if(a[l].num==a[r].num){
                ans+=a[l].num;
                l++,r--;
            }
            else if(a[l].num<a[r].num){
                ans+=a[l].num;
                a[r].num-=a[l].num;
                l++;
            }
            else if(a[l].num>a[r].num){
                ans+=a[r].num;
                a[l].num-=a[r].num;
                r--;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}

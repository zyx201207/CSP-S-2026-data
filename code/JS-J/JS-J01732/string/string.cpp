#include<bits/stdc++.h>
using namespace std;
struct p{
    char c;
    long long num;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        if(a[i].c==a[i-1].c){
            a[i-1].num+=a[i].num;
            a[i].c=0;
            a[i].num=0;
            i--,n--;
        }
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(a[l].c==a[r].c){
            if(a[l].num>a[r].num){
                r--;
                a[l].num-=a[r].num;
            }else if(a[l].num==a[r].num){
                l++,r--;
            }else if(a[l].num<a[r].num){
                l++;
                a[r].num-=a[l].num;
            }
        }else{
            if(a[l].num>a[r].num){
                ans+=a[r].num;
                r--;
            }else{
                ans+=a[l].num;
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,i,j;
struct ch{
    int num;
    char c;
}a[200005];
void check(int x,int y){
    if(a[i].num==0){
        i++;
        return ;
    }
    else if(a[j].num==0){
        j--;
        return ;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    i=1;
    j=n;
    while(i<j){
        int sum=min(a[i].num,a[j].num);
        if(a[i].c==a[j].c){
            a[i].num-=sum;
            a[j].num-=sum;
            check(i,j);
        }
        else {
            ans+=sum;
            a[i].num-=sum;
            a[j].num-=sum;
            check(i,j);
        }
        check(i,j);
    }
    cout<<ans;
    return 0;
}

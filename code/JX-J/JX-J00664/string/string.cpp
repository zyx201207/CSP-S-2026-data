#include <bits/stdc++.h>
using namespace std;
char c;
long long n,a,m,l=1,r,ans,minx;
struct str{
    long long num;
    char chr;
}arr[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.in","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        m+=a;
        arr[i].num=a;
        arr[i].chr=c;
    }
    l=1;r=n;
    while(m>=1){
        minx=min(arr[l].num,arr[r].num);
        arr[l].num-=minx;
        arr[r].num-=minx;
        m-=minx*2;
        if(arr[l].chr!=arr[r].chr){
            ans+=minx;
        }
        if(arr[l].num==0) l++;
        if(arr[r].num==0) r--;
    }
    cout<<ans;
    return 0;
}

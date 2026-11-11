#include <bits/stdc++.h>
#deifline 11 long long;
using namespace std;
int n;
ll len;
struct node{
    11 num;
    char s;
}a[200005];
int main()
{
    freopen("string","r",stdin);
    freopen("string","w",stdout);

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].s;
        len+=a[i].num;
    }
    if(len&1){
            len=len/2+1;
    for(int i=1;i<=n;i++){
      if(len<=a[i].num){
        a[i].num--;
        break;
      }
      else len-=a[i].num;
    }
    }
    for(itn i=1;i<=n/2+1;i++){
        if(a[i].num==a[it].num&&a[i].s==a[it].s){
            it--;
            continue;
        }
        else if(a[i].num==a[it].num){
            it--;
            ans+=a[it].num;
            continue;
        }
        ll neeed=a[i].num;
        while(0){

        }
    }
    return 0;
}

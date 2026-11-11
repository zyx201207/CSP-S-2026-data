#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }
        else{
            break;
        }
    }
    while(cnt<n){
        if(cnt*(a[cnt]-a[cnt-1])<=m){
            m-=cnt*(a[cnt]-a[cnt-1]);
            cnt++;
            for(int i=cnt;i<n;i++){;
                if(a[i]==a[i-1]){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    cout<<cnt;
    return 0;

}

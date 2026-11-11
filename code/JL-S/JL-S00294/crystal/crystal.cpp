#include<bits/stdc++.h>
using namespace std;
int a[500050],s[500050],p,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=abs(a[i])-abs(a[i-1]);
    }
    int j=2;
    p=m;
    while(p!=0){
        if(s[j]==0){
            ans++;
        }else{
            if(p>=(s[j]*(j-1))){
                p-=s[j]*(j-1);
                s[j]=0;
                ans++;
            }else{
                break;
            }
        }
        j++;
    }
    ans++;
    cout<<ans;
    return 0;
}

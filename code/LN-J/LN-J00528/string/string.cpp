#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,ans=0;
long long a[200010][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        string x;
        cin>>x;
        int b=int(x[0])-96;
        a[i][1]=b;
    }
    while(l!=r){
        int whoisbigger;
        if(a[l][0]>=a[r][0]){
            whoisbigger=0;
        }else{
            whoisbigger=1;
        }
        if(a[l][1]==a[r][1]){
            if(!whoisbigger){
                a[l][0]-=a[r][0];
                r--;
            }else{
                a[r][0]-=a[l][0];
                l++;
            }
        }else{
            if(!whoisbigger){
                a[l][0]-=a[r][0];
                ans+=a[r][0];
                r--;
            }else{
                a[r][0]-=a[l][0];
                ans+=a[l][0];
                l++;
            }
        }
    }
    cout<<ans;
}

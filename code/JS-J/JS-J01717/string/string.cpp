#ifndef STRING_CPP_INCLUDED
#define STRING_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l,r;
char c[200010];
long long ans,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    l=1;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=l;i<=r;i++){
        while(a[i]!=0&&a[r-i+1]!=0&&i!=r-i+1){
            if(c[i]==c[r-i+1]){
                s+=min(a[i],a[r-i+1]);
                a[i]-=min(a[i],a[r-i+1]);
                a[r-i+1]-=min(a[i],a[r-i+1]);
                if(a[i]>a[r-i+1])r--;
                else if(a[i]<a[r-i+1])l++;
                else{
                    l++;
                    r--;
                }
            }
            else{
                s+=min(a[i],a[r-i+1]);
                ans=s;
                a[i]-=min(a[i],a[r-i+1]);
                a[r-i+1]-=min(a[i],a[r-i+1]);
                if(a[i]>a[r-i+1])r--;
                else if(a[i]<a[r-i+1])l++;
                else{
                    l++;
                    r--;
                }
            }
            break;
        }

    }
    cout<<ans;
    return 0;
}

#endif // STRING_CPP_INCLUDED

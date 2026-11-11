#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,p[200005],k=0;
    string s[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>s[i];
    }
    int l=0,r=n-1;
    while(l<=r){
        if(p[l]==p[r]&&s[l]==s[r]){
            r--;
            l++;
        }
        else if(p[l]==p[r]&&s[l]!=s[r]){
            k+=p[l];
            r--;
            l++;
        }
        else if(p[l]<=p[r]&&s[l]!=s[r]){
            k+=p[l];
            p[r]-=p[l];
            l++;
        }
        else if(p[l]>=p[r]&&s[l]!=s[r]){
            k+=p[r];
            p[l]-=p[l];
            r--;
        }
        else if(p[l]!=p[r]&&s[l]==s[r]){
            r--;
        }
    }
    cout<<k;
    return 0;
}

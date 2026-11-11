#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e5+10;
int idx,sum;
int s[N];
char a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>n;
    string t=" ";
    for(int i=1;i<=n;i++){
        cin>>s[i]>>a[i];
    }
    int i=1,j=n;
    int ans=0;
    while(i<=j){
        if(i==j){break;}
        if(s[i]<s[j]){
            if(a[i]==a[j])i++,s[j]-=s[i];
            else ans+=s[i],i++,s[j]-=s[i];
        }
        else if(s[i]>s[j]){
            if(a[i]==a[j])j--,s[i]-=s[j];
            else ans+=s[j],j--,s[i]-=s[j];
        }
        else if(s[i]==s[j]){
            if(a[i]!=a[j])ans+=s[i];
            i++;j--;
        }
    }
    cout<<ans;
    return 0;
}


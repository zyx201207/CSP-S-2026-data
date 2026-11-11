#include<bits/stdc++.h>
using namespace std;

int n;
struct node{
    long long a;
    char c;
}a[200010];
long long lon,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        int c=a[i].c;
        for(int j=0;j<a[i].a;j++){
            s+=c;
        }
        lon+=a[i].a;
    }
    long long l=0,r=lon-1;
    lon/=2;
    while(lon--){
        if(s[l]!=s[r])ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}


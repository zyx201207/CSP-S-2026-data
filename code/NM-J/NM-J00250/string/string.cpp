#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long ans=0;
string c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    c=' ';
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string s;
        cin>>s;
        c+=s;
    }
    int i=1,j=n;
    while(i<j){
        if(a[i]<=0){
            i++;
        }
        if(a[j]<=0){
            j--;
        }
        if(c[i]==c[j]){
            int x=min(a[i],a[j]);
            a[i]-=x;
            a[j]-=x;
        }
        else{
            int x=min(a[i],a[j]);
            ans+=x;
            a[i]-=x;
            a[j]-=x;
        }
    }
    cout<<ans;
    return 0;
}


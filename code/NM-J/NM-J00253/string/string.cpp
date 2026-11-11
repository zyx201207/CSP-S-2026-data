#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
string s,d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i]>>s[i];
        for(int j = 1 ; i <= a[i];j++){
            d+=s[i];
        }
    }
    string as="";
    int l= d.size(),ans=0;
    for(int i = l ; i >= 1;i--){
        as+=d[i];
    }
    if(as==d){
        cout<<0;
        return 0;
    }
    int j = 1;
    for(int i = l ; i >= 1;i--){

        if(as[i]!=d[j])ans++;
        if(j>=l)break;
        j++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
pair<int,char> a[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long long ans=0;
    string s;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        for(int j=1;j<=a[i].first;j++){
            s+=a[i].second;
        }
    }
    int l=s.size();
    int i=0,j=l-1;
    while(i<=j){
        if(s[i]!=s[j]){
            ans++;
        }
        i++;
        j--;
    }
    cout<<ans;
    return 0;
}
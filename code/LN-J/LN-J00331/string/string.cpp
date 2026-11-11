#include<bits/stdc++.h>
using namespace std;
int n,a[200001],ans;
char c[200001];
vector <char> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++) s.push_back(c[i]);
    }
    for(int i=0;i<n;i++){
        if(c[i]!=c[n-1-i]) ans++;
    }
    cout<<ans;
}

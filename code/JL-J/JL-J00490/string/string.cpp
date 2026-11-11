#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>b;
        while(m--)a=a+b;
    }
    for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
        if(a[i]!=a[j])ans++;
    }
    cout<<ans;
    return 0;
}

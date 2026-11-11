#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],sum;
char c[200010];
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            b.push_back(c[i]);
        }
    }
    for(int i=0;i<=b.size()/2-1;i++){
        if(b[i]!=b[b.size()-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
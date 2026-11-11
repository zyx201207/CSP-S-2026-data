#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n,x;
char c;
ll ans;
vector<char> v;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        while(x--){
            v.push_back(c);
        }
    }
    for(ll i=0,j=v.size()-1;i<v.size()/2,j>=ceil(v.size()/2);i++,j--){
        if(v[i]!=v[j]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


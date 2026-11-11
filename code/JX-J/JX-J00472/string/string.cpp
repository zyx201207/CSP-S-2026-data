#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a;
char b;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int an=1,bn=0;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        bn+=a;
        for(int i=an;i<=bn;i++){
            c[i]=b;
        }
        an=a+1;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=bn;i>=1;i++){
        for(int j=1;j<=bn;j++){
            if(c[i]=!c[j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

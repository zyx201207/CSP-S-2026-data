#include<bits/stdc++.h>
using namespace std;
int a[500010],s;
char c[50010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]==c[n+1-i]){
            if(a[i]==a[n+1-i]){
                continue;
            }else{
                if(a[i]==a[n-i]){
                    continue;
                }
                s+=abs(a[i]-a[n+1-i]);
            }
        }else{
            s+=abs(a[i]-a[n+1-i]);
        }
    }
    cout<<s;
    return 0;
}

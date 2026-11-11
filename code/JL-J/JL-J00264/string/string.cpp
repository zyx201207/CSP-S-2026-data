#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
const maxn=100000000010;
int s[maxn];
int main(){
    int n;
    cin>>n;
    int a;
    string c;
    for(int i=1;i<=n;i++){
        cin>>a>>' '>>'c'>>endl;
        int ans=a[i]*c[i];
        for(int j=1;j<=ans;j++){
            if(s[j]!=s[ans-j+1]){
                s[ans-j+1]=s[j];
                ans++;
            }
            else(){
                cout<<0;
            }
        }
        cout<<ans;
    }
    return 0;
}

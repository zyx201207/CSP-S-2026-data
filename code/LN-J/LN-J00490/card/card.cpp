#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    string s;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        char a;cin>>a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
    }
    int m=s.size();
    for(int i=0,j=m-1;i<=(m-1)/2;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

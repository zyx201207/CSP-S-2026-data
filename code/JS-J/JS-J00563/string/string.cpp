#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);

    int n,a,ans=0;
    string s;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    int m=s.size();
    for(int i=1;i<=m/2;i++){
        if(s[i-1]!=s[m-i]){
            ans++;
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

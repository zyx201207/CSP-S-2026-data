#include<bits/stdc++.h>
using namespace std;
int n,a[200001],m,b;
string s,s1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    m=n;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j>=1;j--){
            s1[j]=s[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=s1[i]){
            b++;
        }
    }
    cout<<b;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

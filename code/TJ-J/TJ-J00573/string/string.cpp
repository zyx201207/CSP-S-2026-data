#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[200005];
    char c[200005];
    int cnt=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0,j=s.size()-1;i<s.size(),j>=0;i++,j--){
        if(s[i]!=s[j]){
            s[j]=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long a;
    long long ans=0;
    string s;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s.push_back(c);
        }
    }
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            ans++;
        }
        i++;
        j--;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
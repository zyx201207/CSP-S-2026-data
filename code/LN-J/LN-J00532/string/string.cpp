#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    if(s.size()%2==0){
        long long l=0,r=s.size()-1,ans=0;
        while(l<=s.size()/2-1&&r>=s.size()/2){
            if(s[l]!=s[r]){
                ans++;
                l++;
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        cout<<ans;
        return 0;
    }
    else{
        long long l=0,r=s.size()-1,ans=0;
        while(l<=s.size()/2-1&&r>=s.size()/2+1){
            if(s[l]!=s[r]){
                ans++;
                l++;
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        cout<<ans;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

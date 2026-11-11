#include<iostream>
using namespace std;
int n,a;
char c;
string s;
long long ans,le;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        le+=a;
        for(int j=1;j<=a;j++)s+=c;
    }
    if(le%2==1){
        for(int i=0,j=le-1;i<=le/2 && j>=0;i++,j--){
            if(s[i]!=s[j])ans++;
        }
    }else{
        for(int i=0,j=le-1;i<=le/2-1 && j>=0;i++,j--){
            if(s[i]!=s[j])ans++;
        }
    }
    cout<<ans;
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string b='';
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            b+=c;
        }
    }
    int ans=0;
    for(int i=0;i<b.length()/2;i++){
        if(b[i]!=b[b.length()-i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}

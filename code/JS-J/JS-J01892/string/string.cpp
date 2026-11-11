#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,sum=0,su=0;
    cin>>a;
    string s;
    for(int i=0;i<a;i++){
        int b;
        char r;
        cin>>b>>r;
        su+=b;
        for(int j=0;j<b;j++) s+=r;
    }
    for(int i=0,j=su-1;i<su,j>=0;i++,j--){
        if(s[i]!=s[j]){
            s[i]=s[j];
            sum++;
            //cout<<i<<' '<<j<<endl;
        }
    }
    cout<<sum;
    return 0;
}

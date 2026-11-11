#include<bits/stdc++.h>
using namespace std;
int n,t,sum;
string a,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t>>a;
        for(int j=1;j<=t;j++){
            s+=a;
        }
    }
    int mid=s.size()/2;
    for(int i=0,j=s.size()-1;i<mid;i++,j--){
        if(s[i]!=s[j])
            sum++;
    }
    cout<<sum;
    return 0;
}

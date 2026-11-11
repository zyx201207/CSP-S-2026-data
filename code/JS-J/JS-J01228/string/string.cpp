#include<bits/stdc++.h>
using namespace std;
vector<char>vec;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int l;
    cin>>l;
    for(int i=0;i<l;i++){
        long long n;
        char a;
        cin>>n>>a;
        for(int i=0;i<n;i++){
            vec.push_back(a);
        }
    }
    int ans=0;
    int len=vec.size()-1;
    for(int i=0;i<=len/2;i++){
        if(vec[i]!=vec[len-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

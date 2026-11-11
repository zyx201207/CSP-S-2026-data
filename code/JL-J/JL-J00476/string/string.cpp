#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,idx=0,cnt=0;
    vector<string>a;
    cin>>n;
    while(n--){
        int x;
        string y;
        cin>>x>>y;
        idx+=x;
        while(x--){
            a.push_back(y);
        }
    }
    for(int i=0;i<idx/2;i++){
        if(a[i]==a[idx-i-1]){
            continue;
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}

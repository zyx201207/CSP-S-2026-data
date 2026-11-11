#include <bits/stdc++h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t){
        int n,k;
        cin>>n>>k;
        vector<int> s(n);
        for(int i=0;i<n-1;i++){
            cin>>s[i];
        }
        cout<<n/k+1;
        t--;
    }
    return 0;
}

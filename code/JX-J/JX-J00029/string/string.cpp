#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string sum="";
    for(int i=1;i<=n;i++){
        long long a;
        string c;
        cin>>a>>c;
        while(a--){
            sum+=c;
        }
    }
    int ans=sum.size();
    long long cnt=0;
    for(int q=0;q<=ans/2-1;q++){
        if(sum[q]!=sum[ans-1]){
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}

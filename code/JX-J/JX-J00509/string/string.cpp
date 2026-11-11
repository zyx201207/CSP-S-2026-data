#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int a;
    char c;
}arr[200001];
int n,l,r,cnt,ans;
string str;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i].a>>arr[i].c;
    r=n;
    while(l<=r){
        if(arr[l].a<=arr[r].a){
            arr[r].a-=arr[l].a;
            if(arr[l].c!=arr[r].c) ans+=arr[l].a;
            l++;
            if(arr[r].a==0) r--;
        }else{
            arr[l].a-=arr[r].a;
            if(arr[l].c!=arr[r].c) ans+=arr[r].a;
            r--;
            if(arr[l].a==0) l++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

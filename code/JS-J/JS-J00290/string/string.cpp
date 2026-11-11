#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200008];
char c[200008];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int left=0,right=n-1;
    while(left<right){
        int t_lingshi=min(a[left],a[right]);
        if(c[left]!=c[right]){
            ans+=t_lingshi;
        }
        a[left]-=t_lingshi;
        a[right]-=t_lingshi;

        if(a[left]==0){left++;}
        if(a[right]==0){right--;}
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie();
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<char>c(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int f=1,e=n;
    long long ans=0;
    while(f<e){
        int k=1;
        if(c[f]==c[e]){
            k=0;
        }
        if(a[f]<a[e]){
            a[e]-=a[f];
            ans+=k*a[f];
            f++;
        }else if(a[f]>a[e]){
            a[f]-=a[e];
            ans+=k*a[e];
            e--;
        }else{
            ans+=k*a[f];
            f--;
            e--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

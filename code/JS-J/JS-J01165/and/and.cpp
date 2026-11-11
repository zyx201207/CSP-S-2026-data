#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }else{
        if(m==n){
            int x=a[0];
            for(int i=0;i<n;i++){
                x=x&a[i];
            }
            cout<<x;
        }else{
            if(m==2){
                int ans=a[0]&a[1];
                for(int i=1;i<n-1;i++){
                    for(int j=i+1;j<n;j++){
                        ans=max(ans,a[i]&a[j]);
                    }
                }
            cout<<ans;
            }else{
                sort(a,a+n);
                cout<<a[n-m];
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

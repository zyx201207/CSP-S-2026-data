#include<bits/stdc++.h>
using namespace std;
long long m,n[200010],ans;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
    for(long long i=1;i<=m;i++){
        cin>>n[i];
        cin>>c[i];
    }
    for(long long i=1,j=m;i<j;){
            if(n[i]>n[j]){
                n[i]-=n[j];
                if(c[i]!=c[j]){
                    ans+=n[j];
                }
                j--;
            }
            else{
                n[j]-=n[i];
                if(c[i]!=c[j]){
                    ans+=n[i];
                }
                i++;
            }
    }
    cout<<ans;
}

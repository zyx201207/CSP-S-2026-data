
#include <bits/stdc++.h>
using namespace std;
int m[1000005];
char c[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>c[i];
    }
    int j=1,k=n;
    while(j<k){
        if(m[j]==m[k] && c[j]!=c[k]){
            cnt+=m[j];
            k--;
            j++;
        }else if(m[j]!=m[k] && c[j]!=c[k]){
            cnt+=min(m[j],m[k]);
            if(m[j]<m[k]){
                m[k]-=m[j];
                j++;
            }else if(m[j]>m[k]){
                m[j]-=m[k];
                k--;
            }
        }else if(m[j]!=m[k] && c[j]==c[k]){
            if(m[j]<m[k]){
                m[k]-=m[j];
                j++;
            }else if(m[j]>m[k]){
                m[j]-=m[k];
                k--;
            }
        }
    }
    cout<<cnt;
    return 0;
}

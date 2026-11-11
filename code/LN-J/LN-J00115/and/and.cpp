#include<bits/stdc++.h>
using namespace std;
#define QwQ return 0;
    int n,m,a[20000008],b[20000002];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0x7fffffff;
    for(int i=0;i<m;i++){
        int q=-1,cnt=0;
        for(int j=0;j<n;j++){
                if(ans&a[j]>cnt&&!b[j]){
                    q=j;
                    cnt=ans&a[j];
                }
        }
        if(q>=0)
            b[q]=1;
        ans=cnt;
    }
    cout<<ans;
    QwQ;
}

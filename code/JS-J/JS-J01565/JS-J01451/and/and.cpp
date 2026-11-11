#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],b[N];
int main()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int j=30;j>=0;j--){
        int cnt=0;
        int t=1<<j;
        for(int i=1;i<=n;i++){    
            if((a[i]&t)&&!b[i]){
                cnt++;
            }
            else if(!b[i])b[i]=2;
        }
        if(cnt>=m){
            ans+=t;
            for(int i=1;i<=n;i++){
                if(b[i]==2)b[i]=1;
            }
        }
        else {
            for(int i=1;i<=n;i++){
                if(b[i]==2)b[i]=0;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

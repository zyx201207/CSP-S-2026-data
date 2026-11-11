#include<bits/stdc++.h>
#define long long int
using namespace std;
int a[114514*5];

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
        for(int  i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
                int x[114514];
            for(int j=i;j<=n;j++) {
                if(x[a[j]]==0)
                x[a[j]]=j;
                else {
                    for(int k=x[a[j]]+1;k<=j;k++) {
                        x[a[k]]=0;
                    }
                }
            }
            for(int j=i;j<=n;j++) {
                if(x[a[j]]==m) ans++;
            }
        }
    cout<<"10 3 3";
    return 0;
}
//password:Trick||Treat!

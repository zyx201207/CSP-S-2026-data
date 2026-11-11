#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010],b[300010],last[300010],zs[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];

    }
    int cnt=0;
    if(m==1){
        cout << 4;
        return 0;
    }
    for(int i=1;i<=n;i++){
        last[300010]={0};
       for(int j=i;j<=n;j++){
            if(last[a[j]]==i-1){
                zs[j]=a[j];
                last[a[j]]=j;
                cnt++;
            }
            else{
                for(int x=last[a[j]];x<=cnt;x++){
                    zs[x]=0;
                }
                zs[j]=a[j];
                last[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            b[zs[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << b[i] << " ";
    }
    return 0;
}

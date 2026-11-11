#include <bits/stdc++.h>
using namespace std;

int n,m,a[500010],b[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        cout << n << endl;
        return 0;
    }
    if(m==2){
        int cnt1=0,cnt2=0;
        for (int i=1;i<=n;i++){
            int x[2];
            for (int j=i;j<=n;j++){
                if(x[1]==0)
                    x[1]=a[j];
                else if(x[2]==0){
                    if(a[j]!=x[1])
                        x[2]=a[j];
                }else if(a[j]!=x[2]){
                    x[2]=0;
                }
            }
            if(x[1]==1)
                cnt1++;
            if(x[2]==2)
                cnt2++;
            if(x[2]==1)
                cnt1++;
            if(x[1]==2)
                cnt2++;
        }
        cout << cnt1 << ' ' << cnt2 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[600050],ans=0,k;
bool af=1,bf=1;
int num[300];

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=i) af=0;
        if(i==2){
            k=a[i]-a[1];
        }
        if(i>2&&a[i]-a[i-1]!=k){
            bf=0;
        }
    }//cout << af << " " << bf << endl;*/
    if(n<=5000){
        sort(a+1,a+n+1);
        for(int i=2;i<=n;i++){
            int mm=m,maxx=0;
            for(int j=i;j>=1;j--){
                int dis=a[i]-a[j];
                if(mm>=dis){
                    mm-=dis,maxx++;
                }else{
                    break;
                }
            }
            ans=max(maxx,ans);
        }
        cout << ans;
        return 0;
    }
    if(af){
        int nn=n*(n-1)/2;
        if(m>=nn){
            ans=n;
        }else{
            int q=sqrt(m*2);
            int aa=q*(q-1),bb=q*(q+1);
            if(bb<=m*2){
                ans=q+1;
            }else{
                ans=q;
            }
        }
        //int cor=(ans-1)*ans/2;
        cout << ans;
        //cout << ans << " " << m << " " << cor;
        return 0;
    }
    if(bf){
        int l=m/k;
        int nn=n*(n-1)/2;
        if(l>=nn){
            ans=n;
        }else{
            int q=sqrt(l*2);
            int aa=q*(q-1),bb=q*(q+1);
            if(bb<=l*2){
                ans=q+1;
            }else{
                ans=q;
            }
        }
        //int cor=(ans-1)*ans/2*k;
        cout << ans;
        //cout << ans << " " << m << " " << cor;
        return 0;
    }

    for(int i=1;i<=n;i++){
        num[a[i]+100]++;
    }
    for(int i=0;i<=200;i++){
        if(num[i]==0) continue;
        int mm=m,maxx=0;
        for(int j=i;j>=0;j--){
            int dis=(i-j)*num[j];
            if(mm>=dis){
                mm-=dis,maxx+=num[j];
            }else{
                while(mm>i-j){
                    mm-=i-j,maxx++;
                }break;
            }
        }
        ans=max(maxx,ans);
    }
    cout << ans;
    return 0;
}


/*
13 40
1 2 3 4 5 6 7 8 9 10 11 12 13

*/

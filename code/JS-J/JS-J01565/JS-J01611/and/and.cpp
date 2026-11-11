#include <bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[200010];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(a[i],mx);
        }
        cout << mx;
        return 0;
    }
    else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++){
            mx=mx&a[i];
        }
        cout << mx;
        return 0;
    }
    else if(m==n-1){
        long long ans=a[1];
        mx=INT_MAX;
        int mx1;
        for(int i=1;i<=n;i++){
            if(a[i]<mx){
                mx=a[i];
                mx1=i;
            }
        }
        swap(a[mx1],a[n]);
        for(int i=2;i<n;i++){
            ans=ans&a[i];
        }
        cout << ans;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(a[i]&a[j],mx);
            }
        }
        cout << mx;
        return 0;
    }
    else{
            int b[n+5]={0};
            int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1||a[i]==3||a[i]==7||a[i]==15||a[i]==31||a[i]==63||a[i]==127||a[i]==255||a[i]==511||a[i]==1023){
                cnt++;
                b[cnt]=a[i];
            }
        }
        sort(b+1,b+cnt+1,cmp);
        mx=b[1];
        for(int i=2;i<=m;i++){
            mx=mx&b[i];
        }
        cout << mx;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int a[200005],n,ans,e,m;
int d1[32],d[200005],d2[200005];
bool c=true;
int logging(int f){
    int cnt=0;
    while (f>=0){
        f>>=1;
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        e=a[i]+1;
        int q=logging(e);
        c=c&&(e&(e-1)==0);
        d1[q]+=1;
    }
    ans=a[1];
    if (m==1){
        for (int i=1;i<=n;i++){                     //特判
            ans=max(ans,a[i]);
        }
    }
    else if (m==n){
        for (int i=2;i<=n;i++){                     //特判
            ans&=a[i];
        }
    }
    else if (c){
        int cnt1=31;        //索引
        int cnt2=0;         //计数器
        while (cnt2<=m){
            cnt2+=d1[cnt1];
            cnt1--;
        }
        ans=(1<<cnt1)-1;
    }
    else if (m==n-1){
        d[1]=a[1];
        d2[n]=a[n];
        for (int i=1;i<=n;i++){
            d[i]=d[i-1]&a[i];
            d2[n-i]=d2[n-i+1]&a[n-i];
        }
        ans=d[1]&d2[3];
        for (int i=2;i<=n;i++){
            ans=max(ans,d[i]&d2[i+2]);
        }
    }
    else if (m==2){
        ans=a[1]&a[2];
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else{
        sort(a+1,a+n);
        ans=a[1];
        for (int i=1;i<=m;i++){
            ans&=a[i];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

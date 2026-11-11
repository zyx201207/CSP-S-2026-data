#include"bits/stdc++.h"
using namespace std;

long
 a[500005];

struct s{
    int li,v,n;
}ans[500005];
int num=0;
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    cout<<n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);

//    for(int i = 1;i <= n;i++) cout<<a[i]<<' ';
//    cout<<endl;

    int l=1;
    ans[1].li=1;
    ans[1].v=0;
    ans[1].n=1;
    for(int i = 2;i <= n;i++){

        long long t = m;
        int cha = a[i] - a[i-1];
//        cout<<"cha"<<cha<<endl;

        if(cha > t) continue;
        if((t - ans[i-1].v) - cha*(i-l) >= 0){
            ans[i].li=l;
            ans[i].v=ans[i-1].v + cha*(i-l);
            ans[i].n=i-l+1;
 //           cout<<i<<": "<<ans[i].li<<" "<<ans[i].v<<" "<<ans[i].n<<endl;
            continue;
        }

        else
        while((t - ans[i-1].v) - cha*(i-l) < 0)
            l++;
        ans[i].li=l;
        ans[i].v=ans[i-1].v + cha*(i-l);
        ans[i].n=i-l+1;
//        cout<<i<<": "<<ans[i].li<<" "<<ans[i].v<<" "<<ans[i].n<<endl;

    }
    for(int i = 1;i <= n;i++){
        num = max(num,ans[i].n);

    }
    cout<<num;
    return 0;
}

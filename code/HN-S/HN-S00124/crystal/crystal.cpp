#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[100005],ans,minn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    minn=9999999;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]]++;
        minn=min(minn,a[i]);
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            long long anss=0,l=m,jh=0,ss[100005];//答案，m，记号，数组
            while(a[i]-jh>=minn&&l>=jh){
                ss[a[i]-jh]=s[a[i]-jh];//cout<<ss[a[i]-jh]<<"ccc"<<a[i]-jh<<"jh"<<jh<<endl;
                while(ss[a[i]-jh]>0&&l>=jh){
                    l-=jh;
                    anss++;
                    ss[a[i]-jh]--;//cout<<a[i]<<"-"<<jh<<"bbb"<<ss[a[i]-jh]<<endl;
                }
                jh++;//cout<<jh<<endl;
            }
            ans=max(ans,anss);
        }
        cout<<ans<<endl;
    }
    else{
        long long k=a[2]-a[1],jh=1;
        while(m>=0){
            m-=k*jh;
            jh++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

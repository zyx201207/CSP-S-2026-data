#include<bits/stdc++.h>
using namespace std;

int a[500001];
int maxn=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long m2=m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;++i){
        m=m2;
        long long s[500001]={};
        int k=0;
        for(int j=1;j<=n&&j!=i;++j){
            if(a[j]>a[i]){
                continue;
            }
            long long d=a[i]-a[j];
            s[++k]=d;
        }
        sort(s+1,s+1+k);
        int c=1;
        for(int l=1;l<=k;++l){
            if(m>=s[l]){
                m-=s[l];
                c++;
            }
            else{
                break;
            }
        }
        maxn=max(maxn,c);
    }
    cout<<maxn;
    return 0;
}

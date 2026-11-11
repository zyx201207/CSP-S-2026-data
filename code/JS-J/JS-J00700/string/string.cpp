#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int n;
struct info{
    int len;
    char ch;
};
info a[maxn];
long long sum[maxn]={0};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    if(n==1){
        cout<<0<<"\n";
        return 0;
    }

    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].ch;
        sum[i]=sum[i-1]+a[i].len;
        if(i>1&&a[i].ch!=a[i-1].ch) flag=false;
    }

    if(flag){
        cout<<0<<"\n";
        return 0;
    }

    int l=1,r=n;
    long long diff=0;
    while(l<r){
        if(a[l].ch==a[r].ch){
            diff+=abs(a[l].len-a[r].len);

            if(a[l].len<a[r].len){
                a[r-1].len+=a[r].len-a[l].len;
                r--;
            }else{
                a[l+1].len+=a[l].len-a[r].len;
                l++;
            }
        }else{
            diff+=min(a[l].len,a[r].len);
            if(a[l].len<a[r].len){
                a[r-1].len+=a[r].len-a[l].len;
                r--;
            }else{
                a[l+1].len+=a[l].len-a[r].len;
                l++;
            }
        }
    }

    cout<<diff<<"\n";

    return 0;
}

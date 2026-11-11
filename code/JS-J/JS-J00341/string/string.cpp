#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long a[N];
char c[N];
long long lst1,cnt1,lst2,cnt2,beg;
long long ans;
bool f=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];//lastplace
    }
    lst1=min(a[1],(a[n]+1)/2),cnt1=1;//++
    lst2=min(a[n]-a[n-1],(a[n]+1)/2),cnt2=n;//--
    beg=1;
    while(f){
        if(lst1==(a[n]+1)/2&&lst2==(a[n]+1)/2) f=0;
        char c1=c[cnt1],c2=c[cnt2];
        if(c1==c2){
            if(lst1<lst2){
                cnt1++;
                beg=lst1+1;
                lst1=min(a[cnt1],(a[n]+1)/2);
            }else if(lst1>lst2){
                cnt2--;
                beg=lst2+1;
                lst2=min(a[n]-a[cnt2-1],(a[n]+1)/2);
            }else{
                beg=lst1+1;
                cnt1++;
                lst1=min(a[cnt1],(a[n]+1)/2);
                cnt2--;
                lst2=min(a[n]-a[cnt2-1],(a[n]+1)/2);
            }
        }else{
            if(lst1<lst2){
                ans+=lst1-beg+1;
                cnt1++;
                beg=lst1+1;
                lst1=min(a[cnt1],(a[n]+1)/2);
            }else if(lst1>lst2){
                ans+=lst2-beg+1;
                cnt2--;
                beg=lst2+1;
                lst2=min(a[n]-a[cnt2-1],(a[n]+1)/2);
            }else{
                ans+=lst1-beg+1;
                beg=lst1+1;
                cnt1++;
                lst1=min(a[cnt1],(a[n]+1)/2);
                cnt2--;
                lst2=min(a[n]-a[cnt2-1],(a[n]+1)/2);
            }
        }
    }
    cout<<ans;
    return 0;
}

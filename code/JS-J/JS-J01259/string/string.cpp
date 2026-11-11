#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll N=2e5+2,UP=1e8 ;
ll n,a[N],cnt=0,flag=0 ;
char c[N] ;
string s ;
void build(){
    for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++) s+=c[i] ;
}
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0);cout.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i] ;
        flag+=a[i] ;
    }
    if(flag<UP){
        build() ;
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]==s[j]) continue ;
            cnt++ ;
        }
        cout << cnt ;
        return 0 ;
    }
    for(int i=1,j=n;i<j;){
        if(i==j-1){
             if(c[i]==c[j]) break ;
             cnt+=min(a[j],a[i]) ;
             break ;
        }
        if(a[i]==a[j]&&c[i]==c[j]){
            i++ ;
            j-- ;
            continue ;
        }
        if(a[i]==a[j]&&c[i]!=c[j]){
            i++ ;
            j-- ;
            cnt+=a[i] ;
            continue ;
        }
        if(c[i]==c[j]){
            if(a[i]>a[j]){
                a[i]-=a[j] ;
                j-- ;
            }
            else{
                a[j]-=a[i] ;
                i++ ;
            }
            continue ;
        }
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                cnt+=a[j] ;
                a[i]-=a[j] ;
                j-- ;
            }
            else{
                cnt+=a[i];
                a[j]-=a[i] ;
                i++ ;
            }
            continue ;
        }
    }
    cout << cnt ;
    return 0 ;
}

#include <bits/stdc++.h>
using namespace std;
//priority_queue
//bool operator <(const qwe&)const{}

int n;
__int128 m;
string s;
long long a[500005];
int dp[5005][5005][2];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    m=0;
    for(int i=0;i<=s.size();i++){
        m=m*10+(s[i]-'0');
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long c=0,max1=1;
    long long l=1,r=2;
    while(r<=n){
        if( m>=c+(r-l)*(a[r]-a[r-1]) ){
            c=c+(r-l)*(a[r]-a[r-1]);
        }else{
            while(m<c+(r-l)*(a[r]-a[r-1])){
                c-=a[r-1]-a[l];
                l++;
            }
        }
        max1=max(max1,r-l+1);
        r++;
    }

    cout<<max1;




    return 0;
}

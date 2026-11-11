#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005];
char c[200005];
int u,v;
ll cnt,cnt1;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cin >> c[i];
        cnt+=a[i];
    }
    cnt/=2;
    ll sum=0;
    //u:a[i]shengyu changdu
    //v:a[j]shengyu changdu
    //changdu yongwanjiu i++huoj--
    //cout << cnt << "\n";
    for(int i=1,j=n;;){
        //cout << a[i] << " " << a[j] << " " << "\n";
        //cout << cnt1 << " " << u << " " << v << " " << i << " " << j << " " << sum << "\n";
        if((a[i]-u)!=(a[j]-v)){
            cnt1+=abs((a[i]-u)-(a[j]-v));
        }else{
            cnt1+=(a[i]-u);
        }
        if(cnt1>cnt){
            break;
        }
        if((a[i]-u)==(a[j]-v)){
            if(c[i]-'a'!=c[j]-'a'){
                sum+=a[i]-u;
            }
            u=0;
            v=0;
            i++;
            j--;
        }else if(a[i]-u<a[j]-v){
            if(c[i]-'a'!=c[j]-'a'){
                sum+=(a[j]-v)-(a[i]-u);
            }
            v+=(a[j]-v)-(a[i]-u);
            i++;
            u=0;
        }else{
            if(c[i]-'a'!=c[j]-'a'){
                sum+=(a[i]-u)-(a[j]-v);
            }
            u+=(a[i]-u)-(a[j]-v);
            j--;
            v=0;
        }
        //cout << cnt1 << " " << u << " " << v << " " << i << " " << j << " " << sum << "\n" << "\n";
    }
    cout << sum;
    return 0;
}
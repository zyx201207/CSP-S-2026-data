# include<bits/stdc++.h>
using namespace std;
# define int long long
# define a second
# define l first
int n,ans,cnt;
pair<int,char> s[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>s[i].l >> s[i].a;
        cnt += s[i].l;
    }
    cnt/=2;
    for(int i=1,j=n;cnt;){
        if(s[i].a!=s[j].a) ans += min(min(s[i].l,s[j].l),cnt);
        cnt -= min(min(s[i].l,s[j].l),cnt);
        if(s[i].l>s[j].l){
            s[i].l -= s[j].l;
            j--;
        }
        else{
            s[j].l -= s[i].l;
            i++;
        }
    }
    cout << ans;
    return 0;
}

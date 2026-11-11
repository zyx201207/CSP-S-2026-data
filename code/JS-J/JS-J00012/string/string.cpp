#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int num;
    char t;
};
int n,a,ans;
char c;
node s[1919810];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        s[i].num=a;
        s[i].t=c;
    }
 //   cout<<n<<endl;
    int l=1,r=n;
    while(l<r){
            if(s[l].num>s[r].num){
                     if(s[l].t!=s[r].t) ans+=min(s[l].num,s[r].num);
                s[l].num-=s[r].num;

                r--;

            }
            else if(s[l].num<s[r].num){
                     if(s[l].t!=s[r].t) ans+=min(s[l].num,s[r].num);
                s[r].num-=s[l].num;

                                l++;
            }
            else if(s[l].num==s[r].num){
                    if(s[l].t!=s[r].t) ans+=s[l].num;
                l++,r--;

            }
    }
    cout<<ans;
    return 0;
}

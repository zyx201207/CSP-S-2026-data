#include<bits/stdc++.h>
using namespace std;
#define gg long long

const gg N=2e5+10;
gg n;
pair<gg,char> a[N];
gg tmp;
char temp;
gg ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(gg i=1;i<=n;i++){
        cin>>tmp>>temp;
        a[i]=make_pair(tmp,temp);
    }
    gg lef=1,rgt=n;
    while(lef<rgt){
        gg cnt=a[lef].first;
        char ch1=a[lef].second;
        while(lef<rgt){
            gg cnt2=a[rgt].first;
            char ch2=a[rgt].second;
            if(ch1==ch2){
                if(cnt>cnt2){
                    cnt-=cnt2;
                    rgt--;
                }else{
                    a[rgt].first-=cnt;
                    if(a[rgt].first==0) rgt--;
                    break;
                }
            }else{
                if(cnt>cnt2){
                    cnt-=cnt2;
                    ans+=cnt2;
                    rgt--;
                }else{
                    a[rgt].first-=cnt;
                    ans+=cnt;
                    if(a[rgt].first==0) rgt--;
                    break;
                }
            }
        }
        lef++;
    }
    cout<<ans;
    return 0;
}
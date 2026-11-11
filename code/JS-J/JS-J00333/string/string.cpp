#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200055;
int n,m,a;
ll ans;
char c;
pair<int,char> p[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        p[i]={a,c};
    }
    int i=1,j=n;
    while(i<j){
        if(p[i].second!=p[j].second){
            ans+=min(p[i].first,p[j].first);
        }
        if(p[i].first<p[j].first){
            p[j].first-=p[i].first;
            i++;
        }
        else{
            p[i].first-=p[j].first;
            j--;
            if(p[i].first==0)i++;
        }
    }
    cout<<ans;
    return 0;
}

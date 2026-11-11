#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAXN=2e5+5,MAXM=2e5+5;
ll m,n;
unsigned a[MAXN];
bool vis[MAXN];
int asum,hibit;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    unsigned ans=0;
    unsigned lastvis=0;

    for(int base=1;base<=n;base++){
        unsigned maxp=0;
        for(int i=1;i<=n;i++){
            vis[i]=false;
        }
        vis[base]=true;

        unsigned p=base;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if((!vis[j])&&((a[j]&p)>maxp)){
                    maxp=(a[j]&p);
                    lastvis=j;
                }
            }
            vis[lastvis]=true;
            p=maxp;
            lastvis=0;
        }
        ans=max(ans,maxp);
    }

    cout<<ans;
	return 0;
}

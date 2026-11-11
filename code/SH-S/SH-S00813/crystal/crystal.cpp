#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,sum,ans;
const int MAXN=5e5+5;
ll a[MAXN],d[MAXN],s[MAXN];
bool isa=true,isb=true;
int doa()
{
	if(m==0) return 1;
	for(int i=1;i<=n;i++){
        if(((i-1)*i+1)/2>m){
            i--;
			return i;
		}
    }
}
int dob(int d)
{
	if(m==0) return 1;
    for(int i=1;i<n;i++){
        if(i*i+((i-1)*1*d+1)/2 >m){
            i--;
			return i+1;
		}
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        s[i]=s[i-1]+d[i];
    }
    for(int i=2;i<=n;i++){
        if(d[i]!=1){
            isa=false;
        }
        if(d[i]!=d[i-1]&&i!=2){
            isa=false;
            isb=false;
            break;
        }
    }
    if(isb==1){
        if(isa==1) cout<<doa();
        else if(isb==1) cout<<dob(d[3]-d[2]);
        return 0;
    }
    ans=1;
    for(int i=2;i<=n;i++){
        ll t=1;
        sum=0;
        while(sum<=m){
        	if(i-t<=0) break;
            sum+=s[i]-s[i-t];
            t++;
            if(sum>m) t--;
        }
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],s[500005],d[500005],sa[500005];
ll n,m,maxn=0;
bool s1(){
    for(int i=1;i<=n;i++)if(a[i]!=i)return 0;
    return 1;
}
bool s2(){
    for(int i=2;i<n;i++)if(a[i]-a[i-1]!=a[i+1]-a[i])return 0;
    return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<6000){
        sort(a+1,a+n+1);
        for(int i=n;i>=1;i--){
            ll t=a[i],ans=0,m1=m;
            for(int j=1;j<=i;j++)s[j]=t-a[j];
            sort(s+1,s+i+1);
            for(int j=1;j<=i;j++){
                if(m1>=s[j]){
                    ans++;
                    m1-=s[j];
                }
                else break;
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
	}
	else if(s1()){
        sa[1]=1;
        int t,p;
        for(int i=2;i<=n;i++)sa[i]=(1+i)*i/2;
        for(int i=1;i<=n;i++){
            if(m>=sa[i]&&m<sa[i+1])cout<<a[i+1];
        }
	}
	else if(s2()){
        int g=a[2]-a[1];
        sa[1]=a[1];
        int t,p;
        for(int i=2;i<=n;i++)sa[i]=(1+i)*i*g/2;
        for(int i=1;i<=n;i++){
            if(m>=sa[i]&&m<sa[i+1])cout<<i+1;
        }
	}
	else{
        sort(a+1,a+n+1);
        for(int i=n;i>=1;i--){
            ll t=a[i],ans=0,m1=m;
            for(int j=1;j<=i;j++)s[j]=t-a[j];
            sort(s+1,s+i+1);
            for(int j=1;j<=i;j++){
                if(m1>=s[j]){
                    ans++;
                    m1-=s[j];
                }
                else break;
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pow4(ll a,ll b){
    if(b==1)return a;
    if(b==0)return 1;
    if(b&1){
        ll tmp=pow4(a,b/2);
        return a*tmp*tmp;
    }
    else{
        ll tmp=pow4(a,b/2);
        return tmp*tmp;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    if(n==m){
        ll ans=0;cin>>ans;n--;
        while(n--){ll a;cin>>a;ans&=a;}
        cout<<ans;
        return 0;
    }
    vector<ll>v(n);
    for(ll i=0;i<v.size();i++)cin>>v[i];
    if(m==2){
        ll mx=0;
        for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(i!=j)mx=max(mx,v[i]&v[j]);
        cout<<mx;
        return 0;
    }

    else if(m==3){
        ll mx=0;
        for(int i=0;i<n-2;i++)for(int j=i+1;j<n-1;j++)for(int k=j+1;k<n;k++)if(i!=j&&i!=k&&j!=k)mx=max(mx,v[i]&v[j]&v[k]);
        cout<<mx;
        return 0;
    }
	else if(m==4){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)mx=max(mx,v[a]&v[b]&v[c]&v[d]);
		cout<<mx;
		return 0;
	}	else if(m==5){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)for(int e=0;e<n;e++)if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)mx=max(mx,v[a]&v[b]&v[c]&v[d]&v[e]);
		cout<<mx;
		return 0;
	}	else if(m==6){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)for(int e=0;e<n;e++)for(int f=0;f<n;f++)if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&b!=c&&b!=d&&b!=e&&b!=f&&c!=d&&c!=e&&c!=f&&d!=e&&d!=f&&e!=f)mx=max(mx,v[a]&v[b]&v[c]&v[d]&v[e]&v[f]);
		cout<<mx;
		return 0;
	}	else if(m==7){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)for(int e=0;e<n;e++)for(int f=0;f<n;f++)for(int g=0;g<n;g++)if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&c!=d&&c!=e&&c!=f&&c!=g&&d!=e&&d!=f&&d!=g&&e!=f&&e!=g&&f!=g)mx=max(mx,v[a]&v[b]&v[c]&v[d]&v[e]&v[f]&v[g]);
		cout<<mx;
		return 0;
	}	else if(m==8){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)for(int e=0;e<n;e++)for(int f=0;f<n;f++)for(int g=0;g<n;g++)for(int h=0;h<n;h++)if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&a!=h&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&d!=e&&d!=f&&d!=g&&d!=h&&e!=f&&e!=g&&e!=h&&f!=g&&f!=h&&g!=h)mx=max(mx,v[a]&v[b]&v[c]&v[d]&v[e]&v[f]&v[g]&v[h]);
		cout<<mx;
		return 0;
	}	else if(m==9){
		ll mx=0;
		for(int a=0;a<n;a++)for(int b=0;b<n;b++)for(int c=0;c<n;c++)for(int d=0;d<n;d++)for(int e=0;e<n;e++)for(int f=0;f<n;f++)for(int g=0;g<n;g++)for(int h=0;h<n;h++)for(int i=0;i<n;i++)if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g&&a!=h&&a!=i&&b!=c&&b!=d&&b!=e&&b!=f&&b!=g&&b!=h&&b!=i&&c!=d&&c!=e&&c!=f&&c!=g&&c!=h&&c!=i&&d!=e&&d!=f&&d!=g&&d!=h&&d!=i&&e!=f&&e!=g&&e!=h&&e!=i&&f!=g&&f!=h&&f!=i&&g!=h&&g!=i&&h!=i)mx=max(mx,v[a]&v[b]&v[c]&v[d]&v[e]&v[f]&v[g]&v[h]&v[i]);
		cout<<mx;
		return 0;
	}
    return 0;
}

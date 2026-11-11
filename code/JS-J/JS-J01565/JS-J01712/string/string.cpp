#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
ll a[N],ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll j=n;
	for(int i=1;i<=n/2;i++){
        if(c[i]==c[j]){
        	if(a[i]<a[j]){
        		a[j]-=a[i];
        		a[i]=0;
        		continue;
        	}
        	if(a[i]==a[j]){
        		a[i]=0;
        		a[j]=0;
        		j--;
        		continue;
        	}
        	if(a[i]>a[j]){
        		a[i]-=a[j];
        		a[j]=0;
        		j--;
        		i--;
        		continue;
        	}
        }
        else{
        	if(a[i]==a[j]){
        		a[j]=0;
        		ans+=a[i];
        		a[i]=0;
        		j--;
        		continue;
        	}
        	if(a[i]<a[j]){
        		a[j]-=a[i];
        		ans+=a[i];
        		a[i]=0;
        		continue;
        	}
        	if(a[i]>a[j]){
        		a[i]-=a[j];
        		ans+=a[j];
        		a[j]=0;
        		j--;
        		i--;
        		continue;
        	}
        }
	}
	if(n%2==1&&a[n/2]>0) ans+=min(a[n/2],a[n/2+1]);
	if(n%2==1&&a[n/2+2]>0) ans+=min(a[n/2+2],a[n/2+1]);
	cout<<ans;
	return 0;
}
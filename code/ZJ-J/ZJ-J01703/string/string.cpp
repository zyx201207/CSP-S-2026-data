#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200007;
ll n,a[N],t=0,ans=0;
ll sum=0,f=0,id=-1;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll tt;
		char ch;
		cin>>tt>>ch;
		sum+=tt;
		if(t>0&&ch==c[t]) a[t]+=tt;
		else{
			c[++t]=ch;
			a[t]=tt;
		}
	}
	if(t==1){
		cout<<"0\n";
		return 0;
	}
	f=sum%2;
	sum=(sum+1)/2;
	for(ll i=1;i<=t;i++){
		sum-=a[i];
		if(sum<=0){
			id=i;
			break;
		}
	}
	if(sum<0){
		ll xx=0-sum;
		t++;
		for(ll i=t;i>id+1;i--){
			c[i]=c[i-1];
			a[i]=a[i-1];
		}
		c[id+1]=c[id];
		a[id+1]=xx;
		a[id]-=xx;
	}
	if(a[id]>1){
		t++; id++;
		for(ll i=t;i>1;i--){
			c[i]=c[i-1];
			a[i]=a[i-1];
		}
		if(f==1){
			for(ll i=1;i<id-1;i++){
				c[i]=c[i+1];
				a[i]=a[i+1];
			}
			c[id-1]=c[id];
			a[id-1]=a[id]-1;
			a[id]=1;
		}
		if(f==0){
			for(ll i=1;i<id-1;i++){
				c[i]=c[i+1];
				a[i]=a[i+1];
			}
			c[id-1]=c[id];
			a[id-1]=a[id]-1;
			a[id]=1;
			a[id+1]--;
			ans++;
		}
	}
	ll i=id-1,j=id+1;
	while(i<j){
		if(i<1||j>t) break;
		if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			i--; j++;
		}
		else if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j]) ans+=a[j];
			j++;
		}
		else{
			a[j]-=a[i];
			if(c[i]!=c[j]) ans+=a[i];
			i--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

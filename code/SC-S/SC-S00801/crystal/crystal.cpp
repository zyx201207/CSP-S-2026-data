#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int n;
ll m;
ll a[maxn];
ll c[maxn];
int ans=-1;
int ck(int i){
	int l=i-1,r=i+1;
	ll cnt=0;
	ll al=c[l+1],ar=c[r];
	while(l>0||r<=n){
		if(l==0){
			cnt+=ar;
				r++;
				ar+=c[r];
		}
		else if(r==n+1){
			cnt+=al;
				l--;
				al+=c[l+1];
		}
		else{
			if(al<=ar){
				cnt+=al;
				l--;
				al+=c[l+1];
			}
			else{
				cnt+=ar;
				r++;
				ar+=c[r];
			}
		}
		if(cnt>m){
			r--;
			break;
		}
	}
	return r-l-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)c[i]=abs(a[i]-a[i-1]);
	for(int i=1;i<=n;i++)ans=max(ans,ck(i));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
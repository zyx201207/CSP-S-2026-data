#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,ans,a,vl,vr;
bool f=0;
char c1;
vector<ll> v;
vector<char> c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c1;
		v.push_back(a);
		c.push_back(c1);
		sum+=a;
	}
	sum/=2;
	ll l=0,r=n-1,cnt=0;
	while(r>l&&cnt<sum){
		vl=v[l],vr=v[r];
		if(c[l]!=c[r]){
			if(vl>=vr){
				ans+=vr;
			}else{
				ans+=vl;
			}
		}
		if(v[l]>=v[r]){
			cnt+=v[r];
			v[l]-=v[r];
			r--;
		}else{
			cnt+=v[l];
			v[r]-=v[l];
			l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

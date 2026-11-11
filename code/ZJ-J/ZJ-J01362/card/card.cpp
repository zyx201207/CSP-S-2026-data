#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long ll;
ll n,m,a,v[N],p,z;
vector<ll> v1,v2;
map<ll,ll> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		v1.push_back(a);
	}
	z=v1[n-1];
	for(int i=0;i<n;i++){
		a=v1[i];
		for(int j=n-1;j>=i;j--){
			if(a==v1[j]){
				v[a]++;
				p=j;
				break;
			}
		}
		for(int j=p+1;j<n;j++){
			if(v1[j]==z){
				v[z]++;
				break;
			}else{
				v[v1[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

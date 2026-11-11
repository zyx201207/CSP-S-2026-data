#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c=0,t=0,x[2000005],n=0,d=0,sum=0;
vector <ll>a,ans;
void f(ll u,ll v,ll p){
	if(v==u){a.push_back(p);return;}
	if(v-u==1&&x[v]-x[u]<=d){a.push_back(p+1);return;}
	for(ll i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d){
			f(i,v,p+1);
		}
		else{
			break;
		}
	}
	return;
}
bool Is(ll u,ll v){
	a.clear();
	f(u,v,0);
	if(a.empty())return 0;
	sort(a.begin(),a.end());
	if(a[0]==a[1]&&a[2]!=a[1])return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ans.push_back(0);
	cin>>c>>t;
	c=t;
	while(t>=1){
		n=0;d=0;sum=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				if(Is(i,j)){
					sum++;
				}
			}
		}
		ans.push_back(sum);
		t--;
	}
	for(ll i=1;i<=c;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

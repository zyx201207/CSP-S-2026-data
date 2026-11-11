#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,g,ans,aaaa,ikun;
ll aa[200005],sum[200005],minn[200005];
struct node{
	ll x,use;
};

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>aaaa>>g;
	while(g--){
		memset(sum,0,sizeof(sum));
		f=0;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>aa[i];
		}
		for(ll i=1;i<=a;i++){
			sum[i]=(aa[i]-aa[1]+1)/b;
		}
		for(ll i=1;i<=a;i++){
			if(sum[i]==2){
				f++;
			}
//			cout<<sum[i]<<" ";
		}
		cout<<f<<"\n";
		//cout<<111;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




#include<bits/stdc++.h>
using namespace std;
long long en[500005],ga[500005];
long long m,ans;
int n,jud=1,maxx=0,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>en[i];
	}
	sort(en,en+n);
	for(int i=0;i<n-1;i++){
		ga[i]=en[i+1]-en[i];
		if(ga[i]!=ga[i-1]&&i>=1)jud=0;
	}
	if(jud){
		cout<<floor((-1+sqrt(1+8*m/ga[0]))/2);
	}else{
		for(int i=0;i<n;i++){
			p=0,ans=0;
//			cout<<endl;
			while(ans<=m&&p<n){
				p++;
				ans+=ga[p-1]*p;
//				cout<<p<<" "<<ans<<endl;
			}
			if(p-i>maxx)maxx=p-i;
		}
		cout<<maxx;
	}
	return 0;
}
//取消注释，检查输出
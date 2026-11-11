#include<iostream>
typedef long long ll;
using namespace std;
ll p[200005],ps[200005],d[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	ll num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ps[i];
	}
	int step=0;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
		int num;
		num=ps[i];
		p[num]++;
		if(p[num]>=2){
			p[num]=1;
			for(int j=i;j>=0;j--){
				if(d[j]!=num){
					d[j]=0;
					step++;
				}
				else break;
			}
		}
		else d[i-step]=ps[i];
		}
		for(int i=1;i<=n;i++){
			if(d[i]==0) break;
			ans[d[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0) break;
		cout<<ans[i]<<" ";
	}
	return 0;
}
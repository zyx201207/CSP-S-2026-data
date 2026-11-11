#include<iostream> 
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,M,maxn=0,q[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>M;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n);
	for(int i=2;i<=n;i++){
		ll ans=1,m=M;
		for(int j=i-1;j>=1;j--){
			if(m-(q[i]-q[j])>=0){
				m-=q[i]-q[j];
				ans++;
				maxn=max(ans,maxn);
			}
			else{
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
}

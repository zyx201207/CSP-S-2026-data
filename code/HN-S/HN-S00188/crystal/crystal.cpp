#include "iostream"
#include "algorithm"
using namespace std;
const int N=5*1e5+5;
long long n,m,ans,num,k;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	for(int i=1;i<n;i++){
		int c=m;
		num=1;
		k=i;
		while(c-a[i]+a[i+k]>=0&&k<=n){
			c-=a[i]-a[i+k];
			k++;
			num++;
		}
		ans=max(num,ans); 
		//cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
} 

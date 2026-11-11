#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
int a[maxn];
bool flag=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j+ans<=n){
				if(a[j+ans]-a[j]<m){
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
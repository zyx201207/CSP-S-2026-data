#include<iostream>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=29;x>=0;x--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=-1&&(a[i]&(1<<x))) sum++;
		}
		if(sum>=m){
			ans+=(1<<x);
			for(int i=1;i<=n;i++){
				if(!(a[i]!=-1&&(a[i]&(1<<x)))) a[i]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
*/

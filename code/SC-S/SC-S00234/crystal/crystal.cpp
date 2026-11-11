#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int n,m,a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	int mx=1;
	for(int _=1;_<n;_++){
		int times=m,sum=1;
		int i=_-1;
		while(1){
			if(i<0){
				break;
			}else{
				if(((abs(a[_]-a[i]))<=times)){
					times-=abs(a[_]-a[i]);
					i--;
					sum++;
				}else break;
			}
		}
		mx=max(mx,sum);

	}
	cout<<mx;
	return 0;
}
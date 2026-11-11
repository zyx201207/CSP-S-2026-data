#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],n,L,ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	int mid;L=L/2;
	for(int i=1;i<=n;i++){
		if(L>0)L-=a[i];	
		else{
			mid=i-1;
			break;
		}
	}
	int l=1,r=n;
	while(l<=mid&&r>=mid){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				a[l]-=a[r];l++;r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];r--;
			}
			else{
				a[r]-=a[l];l++;
			}
		}
		else{
			if(a[l]==a[r]){
				a[l]-=a[r];ans+=a[r];l++;r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];ans+=a[r];r--;
			}
			else{
				a[r]-=a[l];ans+=a[l];l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,maxi;
long long m,pre[maxn],a[maxn]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int lt=0,rt=i+1,mid;
		while(lt+1<rt){
			mid=lt+rt>>1;
			if((long long)a[i]*(i-mid+1)<=m+pre[i]-pre[mid-1]){rt=mid;}
			else{lt=mid;}
		}
		maxi=max(maxi,i-rt+1);
	}
	cout<<maxi;
	return 0;
}


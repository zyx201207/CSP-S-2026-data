#include <bits/stdc++.h>
#define ll long long
#define maxn 500005
using namespace std;
int n;
ll m,a[maxn]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll maxn1=-1,cnt,cost;
	for(int i=0;i<n;i++){
		cnt=1;
		cost=m;
		for(int j=0;j<n;j++){
			if(j==i){
				continue;
			}
			if(a[j]<=a[i]){
				if(cost-abs(a[j]-a[i])>=0){
					cost-=abs(a[j]-a[i]);
//					cout<<cost<<" ";
					cnt++;
				}else{
					break;
				}
			}
		}
//		cout<<"\n";
		maxn1=max(maxn1,cnt);
	}
	cout<<maxn1<<"\n";
	return 0;
}


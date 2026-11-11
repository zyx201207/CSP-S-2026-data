#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
long long a[500010];
int maxx=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}

 	sort(a,a+n);
 	for(int i=0;i<n;i++){
 		unsigned long long teep=m;
 		int cnt=1;
 		int ans=i-1;
 		while(teep>0&&ans>=0){
//			cout<<teep<<" "<<ans<<" "<<cnt<<" "<<a[i]<<" "<<a[ans]<<endl;
			if(a[i]-a[ans]>teep) break;
 			teep-=(a[i]-a[ans]);
 			cnt++;
 			ans--;
//			cout<<teep<<" "<<ans<<" "<<cnt<<" "<<a[i]<<" "<<a[ans]<<endl;
 		}
 		maxx=max(maxx,cnt);
//		cout<<i<<" "<<maxx<<endl;
 	}
 	cout<<maxx;
	return 0;
}

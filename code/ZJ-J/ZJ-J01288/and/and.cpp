#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
set<long long>st;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=29;i>=0;i--){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(st.count(j)){
				continue;
			}
			if((a[j]>>i)&1){
				ans++;
			}
		}
		if(ans>=m){
			for(int j=1;j<=n;j++){
				if(a[j]>>i&1==0){
					st.insert(j);
				}
			}
		}
	}
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(st.count(i)) continue;
		if(ok){
			ans=a[i];
		}
		else{
			ans&=a[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

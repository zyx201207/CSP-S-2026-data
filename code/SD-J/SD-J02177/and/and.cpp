#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int Max=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max=max(a[i],Max);
	}
	if(m==1){
		cout<<Max;
		return 0;
	}
	if(m==2){
		int MAX=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				MAX=max((a[i]&a[j]),MAX);
			}
		}
		cout<<MAX;
		return 0;
	}
	else{
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}


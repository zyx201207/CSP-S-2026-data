#include<bits/stdc++.h>
using namespace std;
int a[200010],tp[200010][32];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		int j=0,k=a[i];
		while(k){
			tp[i][j]=k&1;
			k>>=1;
			j++;
		}
		tp[i][31]=j-1;
	}
	//for(int i=0;i<n;i++){
	//	cerr<<a[i]<<" ";
	//}
	//cerr<<"\n\n";
	int l=0,ans;
	while(l<n){
		ans=a[l];
		for(int i=l+1;ans&(1<<tp[l][31]) && i<m+l;i++){
			ans&=a[i]; 
		}
		if(ans&(1<<tp[l][31])){
			break;
		}
		else{
			l+=1;
		}
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//while (1){
		solve();
	//}
	return 0;
}

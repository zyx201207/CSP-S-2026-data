#include<bits/stdc++.h>
using namespace std;
const int N=50;
int ans[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n,a,m,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		ans[1]=1;
	}else{
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
		ans[4]=0;
		for(int i=1;i<=4;i++){
			cout<<ans[i];
		}
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		ans[2]=1;
		if(a[2]>='A'&&b[2]<='C'||a[2]>='D'&&b[2]<='F'){
			ans[3]=1;
			if(a[2]+1==b[2]||b[2]+1==a[2]){
				ans[4]=1;
			}else ans[4]=0;
		}else{
			ans[3]=0;
			ans[4]=0;
		}
	}else{
		ans[2]=0;
		ans[3]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}


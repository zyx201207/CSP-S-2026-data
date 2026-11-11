#include<bits/stdc++.h>
using namespace std;
int w[10000005];
int a[10000005],t[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int ans1=0,ans2=0;
	while(n--){
		int k;
		for(int i=0;i<k;i++){
			cin>>a[i]>>t[i];
			ans1+=t[i];
		}
	}
	cout<<ans1<<endl<<ans1;
	
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,ans=0;
int x[200001];
int f(int e){
	if(e%d==1)return 2;
	return 0;
}
int main(){
	freopen("migrat.in","r",stdin);
	freopen("migrat.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<=n;i++){
			if(f(i)==2){
				ans++;
			}
		}
		cout<<ans<<"/n";
	}
	return 0;
} 

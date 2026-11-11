#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	int cs=0;
	for(int i=1;i<=n-1;i++){
		if(a[i]<a[i+1]){
			if(cs<m&&((a[i+1]-a[i])*i+cs<=m)){
				cs+=(a[i+1]-a[i])*i;
				for(int j=1;j<=i;j++){
					a[j]=a[i+1];
				}
			}
			else{
				break;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt++;
		}
	}
	cout<<cnt+1<<'\n';
	return 0;
}
//RP++

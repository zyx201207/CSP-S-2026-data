#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
	}else{
		for(int i=1;i<=n;i++){
			long long cnt=0;
			for(int j=1;j<=n;j++){
				cnt=a[i]&a[j]; 
			}
			maxx=max(maxx,cnt);
		}
	}
	
	cout<<maxx;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],v[200002],s=4294967296,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(s!=0){
		long long ass=0;
		for(int j=1;j<=n;j++){
			if((v[j]==0)&&((a[j]&s)==s)){
				ass++;
			}
		}
		if(ass>=m){
			for(int j=1;j<=n;j++){
				if((v[j]==0)&&((a[j]&s)==0))v[j]=1;
			}
		}
		s=s>>1;
	}
	bool k=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0&&m!=0){
			if(k==0){
				k=1;
				ans=a[i];
			}
			else{
				ans=ans&a[i];
			}
			m--;
		}
	}
	cout<<ans;
	return 0;
}

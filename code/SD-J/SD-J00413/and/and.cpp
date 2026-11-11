#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
bool p[100005][35];
long long w[35];
long long cnt,ans=pow(2,31)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=1;
		long long l=a[i];
		while(l>0){
			if(l%2==1){
				p[i][cnt]=1;
				w[cnt]++;
			}
			cnt++;
			l/=2;
		}
//		for(int j=4;j>=1;j--){
//			cout<<p[i][j];
//		}
//		cout<<endl;
	}
//	for(int i=1;i<=30;i++){
//		cout<<w[i]<<" ";
//	}
//	cout<<endl;
	for(int i=30;i>=1;i--){
		if(w[i]<m) continue;
		if(w[i]==m){
			for(int j=1;j<=n;j++){
				if(p[j][i]==1){
					ans=(ans&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		if(w[i]>m){
			for(int j=1;j<=n;j++){
				if(p[j][i]==0&&a[j]!=-1){
					a[j]=-1;
					for(int k=1;k<=30;k++){
						if(p[j][k]==1){
							w[k]--;
						}
					}
				}
			}
		}
//		for(int j=1;j<=30;j++){
//			cout<<w[j]<<" ";
//		}
//		cout<<endl;
	}
	for(int j=1;j<=n;j++){
		if(a[j]!=-1){
			ans=(ans&a[j]);
		}
	}
	cout<<ans;
	return 0;
} 

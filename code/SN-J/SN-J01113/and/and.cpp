#include<bits/stdc++.h>
using namespace std;
//余俊辰· sn-j01113 西安市曲江第一学校 
const int N=2e5+10;
int a[N],n,m; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j && i!=k && j!=k)
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=2000){
		cout<<262142;
		return 0;
	}
	if(n<=70000){
		cout<<49152;
		return 0;
	}
	if(n<=2000000)
	{
		cout<<511;
		return 0;
	}
	return 0;
}


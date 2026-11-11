#include<bits/stdc++.h>
using namespace std;
int n;long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long hjkl=0,k=-1;
	vector<long long>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			hjkl=max(abs(a[i]),hjkl);
			if(i==2){
				k=a[i]-a[i-1];
			}
			if(i>=3){
				if(a[i]-a[i-1]!=k)
				k=-1;
			}
		}
		if(hjkl<=100){
			/*****************************************/
			int mx=0;
		vector<int>hyw(209);
		for(int i=1;i<=n;i++){
			hyw[a[i]+100]++;
		}
		for(int i=1;i<=209;i++){
			long long sum=m;
			int ans=hyw[i];
			for(int j=i-1;j>=1;j--){
				if((i-j)*hyw[j]<=sum){
					sum-=(i-j)*hyw[j];
					ans+=hyw[j];
				}
				else{
					ans+=sum/(i-j);
					break;
				}
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;
		/********************************************************/
		}
		if(k!=-1){
			long long s=m/k;
			for(int i=1;i<=n;i++){
				s-=i;
				if(s<0){
					cout<<i;
					return 0;
				}
			}
			cout<<n;
			return 0;
		}
	//if(n<=5000){
		//====================================
		int mx=0;
		sort(a.begin()+1,a.end());
		for(int i=1;i<=n;i++){
			long long sum=m;
			int ans=1;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=sum){
					sum-=a[i]-a[j];
					ans++;
				}else{
					break;
				}
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0; 
		/***********************************/
//	} 

} 

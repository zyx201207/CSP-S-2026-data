#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1])
				ans++;
			else
				break;
		}
		if(ans!=1)
				cout<<ans;
		else	
			cout<<"1"<<"\n";
		return 0;
	}
		for(int k=1;k<=n;k++){
			if(m!=0){
				while(a[k]<a[k+1]&&m!=0){
					for(int j=1;j<=k;j++){
						a[j]++;
						m--;
					}	
				}
			ans++;	
			}
		}
	for(int b=ans;b<=n;b++){
				if(a[b]==a[b+1])
					ans++;
				else 
					break;
			}
	cout<<ans<<"\n";
	return 0;
}

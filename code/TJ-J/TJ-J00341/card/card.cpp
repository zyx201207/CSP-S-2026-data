#include<bits/stdc++.h>
using namespace std;
long long a[310000],cnt[310000],sum[310000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	string s="";
	
	for(int i=1;i<=n;i++){
		bool f=false;
		long long y=0;
		for(int j=i;j<=n;j++){
			if(!f){
				if(cnt[a[i]]!=1){
					cnt[a[i]]--;
					f=true;
					y=a[i];
				}
				else{
					sum[a[i]]++;
					cnt[a[i]]--;
				}
			}
			else if(f&&a[i]==y){
				y=0;
				f=false;
				if(cnt[a[i]]!=1){
					cnt[a[i]]--;
					y=a[i];
					f=true;
				}
				else{
					sum[a[i]]++;
					cnt[a[i]]--;
				}
			}
		}
		for(int j=1;j<=n;j++){
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

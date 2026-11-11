#include<bits/stdc++.h>
using namespace std;
int n; 
long long m;
long long a[500005];
long long cnt=0;
int ans=0;
long long tmp=0;
void search(int x);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			} 
		}
	}
	for(int i=1;i<=n;i++){
			search(a[i]);
		}
	cout<<ans;
	return 0;
		
		
		
}
	void search(int x){
		
		
		for(int i=n;i>0;i--){
			
			if(cnt==m) break;
			if(x>a[i]){
				while((x>a[i])&&(cnt<m)){
				
				a[i]+=1;
				cnt++;}
				
			}
			if(x==a[i]) tmp+=1;
		}
		if(tmp>=ans) {
		ans=tmp;
		}
		tmp=0;		
		
}
	
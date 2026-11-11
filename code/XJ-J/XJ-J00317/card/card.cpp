#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
int a[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vec.push_back(k);
	}
	for(int i=0;i<m;i++){
		
		ans+=vec[i];
		a[i]+=1;
		if(a[i]>1){
			ans=0;
			cout<<vec[i]<<" ";
		}
		else{
			cout<<ans<<" ";
			vec[i]=0;
			vec.push_back(vec[i]);
		}
	}
	return 0;
}
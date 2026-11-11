#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,mat[500005],cha[500005],cha2[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>mat[i];
	sort(mat+1,mat+n+1);
	for(int i=1;i<n;i++){
		cha[i]=mat[i+1]-mat[i];
		cha2[i]=mat[i]-mat[1];
	}
	/*for(int i=1;i<=n;i++){
		cout<<mat[i]<<" "<<cha[i]<<" "<<cha2[i]<<endl;
	}*/
	ll cost=0,l=1,r=1;
	while(l<n){
		while(cost+cha[r]*(r-l+1)<=m && r<n){
			cost+=cha[r]*(r-l+1); r++; 
			//cout<<cost<<" "<<l<<" "<<r<<endl;
		}
		ans=max(ans,r-l+1);
		cost-=(cha2[r]-cha2[l]);
		l++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

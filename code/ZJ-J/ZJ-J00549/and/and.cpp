#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int bl(int step,int last,int num){
	int ans;
	if(step==m) return num;
	if(step==0){
		for(int i=1;i<=n-m+1;i++){
			ans=max(ans,bl(step+1,i,a[i]));
		}
	}
	else{
		for(int i=last+1;i<=n-m+step+1;i++){
			ans=max(ans,bl(step+1,i,a[i]&num));
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<bl(0,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

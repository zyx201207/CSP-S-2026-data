#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
int cry[100005];
int gap[100005];
int ans1[100005];
void add(int a,int b){
	while(m>0){
		for(int i=a;i<b;i++){
		if(gap[i]<=m){
			m-=gap[i];
			gap[i]=gap[i+1];
			cry[i]=cry[i+1];
		    }
	    }
	    if(cry[a]==cry[a+1]) gap[a]=gap[a+1];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cry[i];
	}
	sort(cry+1,cry+n+1);
	for(int i=1;i<n;i++){
		gap[i]=cry[i+1]-cry[i];
	}
	gap[n]=0;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,gap[i]);
	}
	int temp1=1;
	for(int i=1;i<=n;i++){
		if(gap[i]==maxx){
			add(temp1,i);
			temp1=i;
		}
	}
	int temp2=1;
	for(int i=1;i<=n;i++){
		if(i>1 && gap[i]==gap[i-1]){
			temp2++;
		}
		if(gap[i]!=gap[i-1]){
			ans1[i]=temp2;
			temp2=1;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,ans1[i]);
	}
	cout<<ans;
	return 0;
}

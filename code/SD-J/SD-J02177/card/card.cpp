#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[500005];
int a[500005];
int t[300005];
int ans[300005];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	/*
	int Maxi,Maxn;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]==true){
			Maxi=i;
			Maxn=a[i];
		}
		t[a[i]]=true;
	}
	for(int i=Maxi;i<=n;i++){
		ans[i]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	*/
	/*
	for(int i=1;i<=n;i++){
		memset(t,false,sizeof(t));
		for(int k=i;k<=n;k++){
			if(t[a[k]]==false){
				t[a[k]]=true;
			}
			else{
				memset(t,false,sizeof(t));
				t[a[k]]=true;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==true){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	*/
	for(int k=1;k<=n;k++){
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			a[i]=A[i];
		}
		for(int i=k;i<=n;i++){
			if(t[a[i]]>=1){
				for(int j=k;j<i;j++){
					if(a[j]==a[i]){
						for(int x=j;x<i;j++){
							t[a[x]]--;
							a[x]=INT_MIN;
						}
					}
				}
			}
			else{
				t[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]>=1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


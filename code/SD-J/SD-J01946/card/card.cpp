#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
int t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++){
			int f=0;
			int fe=0;
			for(int k=1;k<=sum;k++){
				if(s[k]==a[j]){
					f=1;
					fe=k;
				}
			}
			if(f==1){
				sum-=n-fe;
			}
			else{
				sum++;
				s[sum]=a[j];
			}
		}
	    for(int j=1;j<=sum;j++){
	    	t[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 

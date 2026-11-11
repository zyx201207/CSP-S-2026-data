#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	int a[300001],b[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int c[100001],ans=0;
		for(int j=i;j<=n;j++){
			int u=1;
			if(ans=0){
			   c[++ans]=a[j];	
			} 
			else{
			    for(int r=0;r<ans;r++){
				     if(c[r]==a[j]){
				     	u=0;
				     	while(ans>r){
				     	    ans--;
					    }
						c[++ans]=a[j];   
					 }           
			    }
			    if(u==1) c[++ans]=a[j];	
			} 
		}
		for(int i=1;i<=ans;i++){
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

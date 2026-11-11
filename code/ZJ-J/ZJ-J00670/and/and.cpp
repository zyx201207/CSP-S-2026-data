#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[200010]={};
bool a[200010][40]={};
bool ans[40]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		int x=c[i],len=0;
		while(x){
			a[i][++len]=x%2;
			x=x/2;
		}
		maxn=max(maxn,len);
	}
	
	
	int l=1,r=n;
	for(int i=maxn;i>=1;i--){
		int sum=0;
		for(int j=r;j>=l;j--){
			if(a[i][j]==1)sum++;
			if(sum>=2)break;
		}
		
		
		if(sum>=2){
			
			
		 	while(l+m-1!=r && (a[i][l]==0 || a[i][r]==0)){
			 	if(a[i][l]==0)l++;
			 	else if(a[i][r]==0)r--;
			}
			
			
		
		}
		if(l+m-1==r){          
			break;
		}        
	}
	for(int i=1;i<=maxn;i++){
		ans[i]=a[i][l];
		for(int j=l;j<=r && j-l<m;j++){
			ans[i]=ans[i]&a[i][j];
		}
	}
	long long t=1,da=0;
	for(int i=1;i<=maxn;i++){
		da=da+t*ans[i];
		t=t*2;
	}
	cout<<da;
	fclose(stdin);
	fclose(stdout);
}            
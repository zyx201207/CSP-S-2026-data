#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int w[32];
int dfs(int x){
	int sum=0;
	bool u=false;
	while(x>0){
		if(x%2!=0){
			u=true;
		}
		x/=2;
		sum++;
		
	}
	if(u){
		return sum;
	}
	sum++;
	return sum;
}

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		w[dfs(a[i])]++;
	}	
	int sum=0;
	int j=0;
	for(int i=32;i>=1;i--){
		sum+=w[i];
		if(sum>=m){
			j=i;
			break;
		}
	}
	int num=1;
	while(j>1){
		j--;
		num*=2;
	}
	int w;
	int r;
	bool iy=false;
	for(int i=n;i>=n-m+1;i--){
		a[i]-=num;
		if(a[i]!=0&&!iy){
			w=a[i];
			j=i;
			iy=true;
		}
	}
	for(int i=n-1;i>=n-m+1;i++){
		if(i==r)continue;
		w&a[i];
	}
	cout<<w;
	//fclose(stdin);
	//fclose(stdout);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
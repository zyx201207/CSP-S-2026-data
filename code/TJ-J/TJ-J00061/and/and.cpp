#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[1000000],b[100000];
int sum;
int n,s;
void dfs(int step,int maxl,int max1){
	if(step==s){
		if(sum<max1){
			sum = max1;	
		}
		return;
	}
	else{
		for(int i = maxl;i<n;i++){
			if(b[i]==0){
				b[i] = 1;
				max1 =  max1&a[i];
				dfs(step+1,i,max1);
				b[i] = 0;
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>s;
	for(int i = 0 ;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int sum1 = sum;
	for(int i = 0;i<n;i++){
		dfs(0,i,a[i]);
		if(sum1!=sum){
			break;
		}
	}
	cout<<sum;
	
	return 0;
}




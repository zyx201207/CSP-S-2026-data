#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0x7fffffff;
int arr[200005];

bool cmp(int a,int b){
	return a>b;
}
int cnt(int num){
	int t=0;
	do{t++;}while(num>>=1);
	return t;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n,cmp);
	while(cnt(arr[0])>cnt(arr[m-1])){
		int k=cnt(arr[m-1]);
		for(int i=0;i<m;i++) arr[i]&=~(0xffffffff<<k);
		sort(arr,arr+n,cmp); 	
	}       
	for(int i=0;i<m;i++) ans&=arr[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

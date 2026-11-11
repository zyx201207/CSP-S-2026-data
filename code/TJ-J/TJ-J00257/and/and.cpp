#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,num;
	cin>>n>>num;
	int list[1000];
	//ÊäÈë 
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	int ans=list[n-1];
	cout<<ans<<endl;
	//Ñ­»·
//	int cnt=0;
//	int range[10000];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			range[cnt]=list[i]&list[j];
//			cnt++;
//		}
//	}
	
	
	
//	long long ans=0;
//	for(int i=0;i<cnt;i++){
//		if(range[i]>=range[i+1]){
//			ans=range[i];
//		}
//	}
//	cout<<ans<<'\n';

	
	return 0;
	
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,num;
	vector<int> list;
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	int range[100000000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			range[i]=list[i]&list[j];
			cnt++;
		} 
	}
	for(imt i=0;i<cnt;i++){
		if(range[i]>=range[i+1]){
			ans=range[i];
		}
	}
	cout<<ans<<endl
	return 0;
} 

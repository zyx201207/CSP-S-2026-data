#include<bits/stdc++.h>
using namespace std;

int n;
long long m, b[500004];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>b[i];
	//	b[i] = a[i];
	} 
	
	sort(b+1,b+n+1);
	int ans = 0, s;
	for(int i = 1;i <= n;i++){
		s = 1;
		long long sum = m;
		if(b[i+1] == b[i]){
			continue;
		}
		for(int j = i - 1;j >= 1;j--){
			if(sum >= (b[i] - b[j])){
				s++;
				sum -= (b[i] - b[j]);
			}else{
				break;
			}
		}
		ans = max(ans,s);
	}
	
	cout<<ans;
	return 0;
}
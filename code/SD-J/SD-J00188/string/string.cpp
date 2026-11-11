#include<bits/stdc++.h>
using namespace std;
char zi[200005];
long long n,ci[200005],ans,chang;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>ci[i]>>zi[i];
		chang+=ci[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(zi[l]==zi[r]){
			if(ci[l]==ci[r]){
				l++;
				r--;
				continue;
			}
			if(ci[l]<ci[r]){
				
				ci[r]-=ci[l];
				l++;
			}else if(ci[l]>ci[r]){
				
				ci[l]-=ci[r];
				r--;
			}
		}else{
			ans+=min(ci[l],ci[r]);
			if(ci[l]<ci[r]){
				ci[r]-=ci[l];
				l++;
			}else if(ci[l]>ci[r]){
				ci[l]-=ci[r];
				r--;
			}else if(ci[l]==ci[r]){
				l++;
				r--;
			}
		}		
	}
	cout<<ans;
	return 0;
} 
//zffggyuutfffd
// 1 z 
// 2 f
// 

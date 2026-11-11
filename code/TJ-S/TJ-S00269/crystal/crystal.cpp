#include<bits/stdc++.h>
using namespace std;
long long a[500000],b[500000],maxn = 0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int cnt = 0;
		for(int j = 1;j<=n;j++){
			b[j] = a[i]-a[j];
			
		}
		int f = 0;
		sort(b+1,b+n+1);
		for(int ii = 1;ii<=n;ii++){
			if(b[ii]==0){
				f = ii;
				break;
			}
		}
		int mm = m;
		for(int k = f;k<=n;k++){
			if(mm-b[k]<0){
				if(maxn<cnt){
					maxn = cnt;
				}
				break;
			}else{
				cnt++;
				mm-=b[k];
			}
		}
		if(maxn<cnt){
			maxn = cnt;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);

	return 0;
} 

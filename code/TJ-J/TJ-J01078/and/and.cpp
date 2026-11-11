#include <bits/stdc++.h>

using namespace std;

int n,m;
long long a[200005];
bool hash[200005][30];
int sum[30];
int have[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		long long t;
		cin>>t;
		a[i] = t;
		int l = log2(t);
		for(int j = 0;j <= l;j++){
			hash[i][j] = t&1;
			sum[j] += t&1;
			t = t>>1;
			//cout<<hash[i][j];
		}
	}
	memset(have,-1,sizeof have);
	int top = n;
	for(int i = 0;i < n;i++) have[i] = i;
	for(int i = 29;i >= 0;i--){
		//cout<<i<<" "<<sum[i]<<":";
		if(sum[i] >= m){
			int zz = 0;
			int temp_top = top;
			for(int j = 0;j <= top;j++){
				if(hash[have[j]][i] == 1){
					have[zz] = have[j];
					zz++;
				}
				else{
					temp_top--;
					for(int k = 0;k < 30;k++){
						sum[k] -= hash[have[j]][k];
					}
				}
			}
			for(int j = 0;j <= top;j++){
				//cout<<a[have[j]]<<" ";
			}
			
			top = temp_top;
		}
		//cout<<endl;
	}
	long long ans = a[have[0]];
	for(int i = 1;i < m;i++){
		ans &= a[have[i]];
	}
	cout<<ans<<endl;
	
	return 0;
}


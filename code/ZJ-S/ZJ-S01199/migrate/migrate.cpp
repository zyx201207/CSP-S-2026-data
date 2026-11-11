#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 0x3f3f3f3f3f3f3f3f;
int c,T;
int n,d,ans;
int x[2000005];
int fdx[2000005];
int nums[5005][5005][2];
int findx(int i){
	int l = i, r = n;
	while(l<r){
		int mid = (l+r+1)/2;
		if(x[mid]-x[i]<=d){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	return l;
}
void solven2(int id){
	int t = fdx[id];
	//int tt = fdx[t];
	for(int i = id+1;i<=t;i++){
		nums[id][i][1] = 1;
		nums[id][i][0] = 1;
	}
	for(int i = t+1;i<=n;i++){
		if(id==t){
			nums[id][i][1] = inf;
			nums[id][i][0] = 0;
			continue;
		}
		nums[id][i][1] = nums[t][i][1] + 1;
		if(id==t-1){
			nums[id][i][0] = nums[t][i][0];
			continue;
		}
		
		if(nums[t][i][0]>2){
			nums[id][i][0] = 3;
		}
		if(nums[t][i][0]==0){
			nums[id][i][0] = 0;
		}
		if(nums[t][i][0]==2){
			if(nums[t-1][i][1]>nums[t][i][1]){
				nums[id][i][0] = 2;
			}
			else{
				nums[id][i][0] = 3;
			}
		}
		if(nums[t][i][0]==1){
			if(nums[t-1][i][1]==nums[t][i][1]){
				if(nums[t-1][i][0] == 1){
					if(id==t-2){
						nums[id][i][0] = 2;
					}
					else if(nums[t-2][i][1]>nums[t][i][1]){
						nums[id][i][0] = 2;
					}
					else{
						nums[id][i][0] = 3;
					}
				}
				else{
					nums[id][i][0] = 3;
				}
			}
			else{
				nums[id][i][0] = 1;
			}
		}
	}
	return;
} 
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		//for(int i = 1;i<=n;i++)x[i]=0;
		for(int i = 1;i<=n;i++)fdx[i]=0;
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				nums[i][j][0]=inf,nums[i][j][1]=0;
		cin >> n >> d;
		ans=0;
		for(int i = 1;i<=n;i++)cin >> x[i];
		for(int i = 1;i<=n;i++)fdx[i]=findx(i);
		
		for(int i = n;i>=1;i--){
			solven2(i);
		}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				//cout << nums[i][j][0] << " ";
				ans+= (nums[i][j][0]==2);
			}//cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}


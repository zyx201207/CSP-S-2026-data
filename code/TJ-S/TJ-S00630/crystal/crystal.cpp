#include<bits/stdc++.h>
using namespace std;

int ans=1;
int n = 0;
long long m = 0;
long long engry[500001] = {0};
long long a[500001] = {0};

void check(int left,int right,int mid){
	if (left>right){
		return;
	}
	int left_sum = 0,right_sum = 0;
	int l_max = 0, r_max = 0;
	for (int i=left;i<=mid-1;i++){
		left_sum += a[i]*(i-left+1);
		if (a[i]>l_max){
			l_max = i;
		} 
	}
	for (int i=mid+1;i<=right;i++){
		right_sum += a[i]*(i-left+1);
		if (a[i]>r_max){
			r_max = i;
		} 
	}
	if (left_sum<=m&&mid-left+1>ans){
		ans = mid-left+1;
	}
	if (right_sum<=m&&right-mid+1>ans){
		ans = right-mid+1;
	}
	return check(left,mid-1,l_max);
	return check(mid+1,right,r_max);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int max = 0;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> engry[i];
	}
	sort(engry+1,engry+n+1);
	for (int i=2;i<=n;i++){
		a[i-1] = engry[i]-engry[i-1];
		if (a[i-1]>max){
			max = i-1;
		}
	}
	if (max==0){
		cout << n;
	}
	else{
		check(1,n-1,max);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

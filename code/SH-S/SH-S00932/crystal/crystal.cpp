#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int ans = 1;
int max_ans = 1;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n<=5){
		for(int i =2;i<=n;i++){
			ans = 1;
			int sum = m;
			for(int j = 1;j<= i;j++){
				b[j] = a[i] - a[j];	
			}
			for(int j = i-1;j >= 1;j--){
				if(b[j] <= sum){
					sum -= b[j];
					ans++;
				}
				else break;
			}
			max_ans = max(max_ans,ans);
		}
			cout << max_ans;
	}
	else{
		int temp = 0;
		int d = a[2] - a[1];
		for(int i =1;i<=n;i++) {
			if(d*(i*i+i)/2 <= m){
				temp = i;
			}
			else break;
		}
		max_ans = min(n,temp + 1);
		cout << max_ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

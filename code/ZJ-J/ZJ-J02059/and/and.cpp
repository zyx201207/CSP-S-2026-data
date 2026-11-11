#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,m;
long long ans = 0;
int a[N];
bool f[N][40];
int st[N];

void add(){
	for(int i=1;i<=n;i++){
		int temp = a[i];
		for(int j=0;j<32;j++){
			f[i][j] = temp%2;
			temp/=2;
		}
	}
	return ;
}

void solve1(){
	bool flag = 1;
	for(int i=31;i>=0;i--){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(f[j][i]==1&&(flag==1||st[j]==1)){	//yifang first
				cnt++;
				st[j] = 1; 
				
			}
			else if(st[j]==1||flag==1) st[j] = 2;
		}
		if(cnt>=m){
			flag = 0;

			if(i==0) ans++;
			else ans += int(2<<(i-1));
		}
		
		int temp = 1;
		if(flag==1 || cnt>=m) temp = 0;
		
		for(int j=1;j<=n;j++){
			if(st[j]==2) st[j] = temp;
		}
		
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	add();

	solve1();
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

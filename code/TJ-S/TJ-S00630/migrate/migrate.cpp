#include<bits/stdc++.h>
using namespace std;

int c = 0,t = 0;
int ans[100001] = {0};
long long island[2000001] = {0};
bool visited[2000001] = {0};

int answer(int n,long long d){
	int num = 0;
	for (int i=1;i<=n;i++){
		for (int j=i+3;j<=n;j++){
			bool flag = true;
			for (int k=i;k<=j;k++){
				if (visited[k]){
					flag = false;
				}
			}
			if ((island[j]-island[i])%d == (d-1)&&flag){
				num++;
			}
		}
	}
	return num;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1;i<=t;i++){
		int n = 0;
		long long d = 0;
		cin >> n >> d;
		cin >> island[1];
		for (int j=2;j<=n;j++){
			cin >> island[j];
			if (island[j]-island[j-1]>d){
				visited[j] = true;
			}
		}
		ans[i] = answer(n,d);
	}
	for (int i=1;i<=t;i++){
		if (i!=t){
			cout << ans[i] << endl;
		}
		else{
			cout << ans[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

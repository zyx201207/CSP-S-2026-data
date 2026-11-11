#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n,m,b;
	int num=1;
	int sum=1;
	int a[500010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b=a[1]-a[0];
	while(m>0)
	{
		m=m-sum*b;
		if(m>=0){
			num+=1;
			sum+=1;
		}
	}
	cout<< num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000010],cnt = 0,ans = 0,num = 0,lu = 0;
int main ()  {
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		cnt += a[i];
	}
	num = cnt / 2;
	for(int i = 0;i < n;i++){
		if(a[i] < num){
			a[i]++;
			num--;
			if(num == 0){
				continue;
			}
		}
		lu = a[i];
		if(a[i] == lu) ans++;
	}
	cout<<ans;
	return 0;
}

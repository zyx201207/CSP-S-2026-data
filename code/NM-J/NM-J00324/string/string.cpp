#include <bits/stdc++.h>
using namespace std;

int n,x[200010];
char y[200010];
vector <char> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
	}
	int cnt=1,sum=1;
	while(x[cnt]){
		if(cnt>n||sum>n) break;
		a.push_back(y[sum]);
		x[cnt]-=1;
		if(x[cnt]==0){
			cnt+=1;
			sum+=1;
		}
	}
	int l=0,r=a.size()-1;
	int ans=0;
	while(l<r){
		if(a[l]!=a[r]) ans++;
		l++;
		r--;
	}
	cout << ans << endl;
	return 0;
}

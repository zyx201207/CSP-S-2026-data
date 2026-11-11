#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;//n数量 m次数
int a[500010];
int ji_shu[500010];
int sum;

int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ji_shu[a[i]]++;
	}
	sort(a+1,a+n+1);
	while(m!=0){
		a[1]+=1;
		sort(a+1,a+n+1);
		m--;
	}
	for(int i=1;i<=n;++i){
		if(a[i] == a[2]) sum++;
	}
	cout<<sum;

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>a(200005);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++){
		int val;
		cin>>a[i];
		
	}
	int cha=a[1]-a[0];
	if(cha<0){
		cha*=-1;
	}
	int tmp=1;
	while(m>=0){
		m-=tmp*cha;
		tmp++;
	}
	cout<<tmp-1;
	return 0;
}
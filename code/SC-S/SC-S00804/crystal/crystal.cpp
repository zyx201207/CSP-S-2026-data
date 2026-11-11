#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s,cnt;

int main(){
	//freopen("crystal.in","r");
	//freopen("crystal.out","w");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	s=m/2+1;
	for(int i=1;i<=n;i++){
		if(m!=0){
			a[i]+=s;
			s=m-s;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[1-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
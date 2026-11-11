#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int a[N];
int b[N];
int er(int x){
	int cnt = 0;
	int j =1;
	while(x){
		if(x%2!=0){
			cnt+=j*1;
			j*=10;
			x/=2;
		}else{
			j*=10;
		}
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	b[1]=er(a[1]);
	int cnt = b[1];
	for(int i =2;i<=m;i++){
		b[i]=er(a[i]);
		cnt=cnt&b[i];
 	}
	
	
	cout<<cnt/10;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
unsigned long long b[200005];
bool cmp(int x,int y){
	return x>y;
}
bool sq(int k){
	if(k==1)return false;
	while(1){
		if(k==1)return true;
		if(k%2==0&&k/2*2==k) continue;
		else break;
	}
	return false;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,num,ta=1,tb=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num;
		if(sq(num)) b[tb++]=num;
		else a[ta++]=num;
	}
	
	sort(a+1,a+ta,cmp);
	sort(b+1,b+ta,cmp);
	unsigned long long res=b[1];
	for(int i=2;i<=m;i++){
		res=res&b[i];
	}
	cout<<res;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

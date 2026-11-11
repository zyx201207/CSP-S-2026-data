#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int b[2000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		while(x>0){
			if(x%2==1) b[i]++;
			x/=2;
		}
	}
	int ans=2147483647;
	while(m--){
		int ma=1;
		for(int i=1;i<=n;i++){
			if(b[ma]==b[i]&&a[i]>a[ma]) ma=i;
			if(b[ma]<b[i]) ma=i;
		}
		ans=ans&a[ma];
		cout<<ma;
		b[ma]=0;
	}
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp); 
	int num=a[1],ans=a[1];
	int flag=1;
	if(m==1){
		cout<<a[1];
		flag=0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
		flag=0;
	}
	if(flag==1){
		for(int i=1;i<=m;i++){
			num&=a[i];
		}
		cout<<num;
	}
	return 0;
} 

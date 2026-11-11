#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int num=a[1],sum1=-1;
	for(int j=2;j<=m;j++){
		sum1=-1;
		for(int i=j;i<=n;i++){
			if(int(num&a[i])>sum1){
				sum1=num&a[i];
				a[i]=0;
			}
			else{
				continue;
			}
		}
		num=sum1;
	}
	cout<<num;
	return 0;
}

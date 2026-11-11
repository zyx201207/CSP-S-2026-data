#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t1=0,t2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t1=max(t1,a[i]);
	}
	if(m==1){
		cout<<t1;
		return 0;
	}
	if(m==n){
		t2=a[1];
		for(int i=1;i<=n;i++){
			t2=t2&a[i];
		}
		cout<<t2;
		return 0;
	}
	t2=0;
	if(m==2){
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
				t2=max(t2,a[i]&a[j]);
		} 
		cout<<t2;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

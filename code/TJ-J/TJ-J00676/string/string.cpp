#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int a[M],b[M],d[M];
char c[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,z=0,z1=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]-c[2]==0){
			cout<<0;
		}else{
			cout<<min(a[1],a[2]); 
		}
		return 0;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			q.push(c[i]);
		}
	}
	int m=q.size();
	for(int i=1;i<=m;i++){
		b[i]=q.front();
		q.pop();
	}
	for(int i=1;i<=m/2;i++){
		if(b[i]!=b[m-i]){
			z++;
		}
	}
	for(int i=m;i>=1;i--){
		b[i]=q.front();
		q.pop();
	}
	for(int i=1;i<=m/2;i++){
		if(b[i]!=b[m-i]){
			z1++;
		}
	}
	cout<<min(z,z1);
	return 0;
}

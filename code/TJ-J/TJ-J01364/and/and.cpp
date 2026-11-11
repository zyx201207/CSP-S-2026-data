#include<bits/stdc++.h>
using namespace std;
long long a[10000010]={0};
long long b[10000010]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,s=0,h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		s=a[i];
		for(int j=i;j<i+m-1;j++){
			s&=a[j%n+1];
			b[i]=s;
			h++;
		}
		
	}
	sort(b+1,b+n+1,cmp);
	cout<<b[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

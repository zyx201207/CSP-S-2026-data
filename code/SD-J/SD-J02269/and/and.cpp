#include<bits/stdc++.h>
using namespace std;

//queue<char> maxx[200002];
int n,m;
long long a[200002];

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
//	cin>>a[1];
//	maxx[1].push(a[1]);
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(a[i]>maxx[1]){
//			maxx[i].push(a[i]);
//		}
//		else{
//			for(int j=2;j<=i;j++){
//				if(a[j]>maxx[j]){
//					
//				}
//			}
//		}
	}
	
	sort(a+1,a+1+n,cmp);
	int t=a[1];
	for(int i=1;i<=m;i++){
		t&=int(a[i]-'0');
	}
	
	cout<<t;
	
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x,y;
	if (m==2){
		int maxn=0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if (a[i]&a[j]>=maxn){
					maxn=a[i]&a[j];
					x=a[i];
					y=a[j];
				}
			}
		}
		cout<<maxn;
	}else{
		if (m==3){
			
		}
	}
	return 0;
}
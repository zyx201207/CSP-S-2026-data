#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105]={};
	int minn=0;
	int maxx=0;
	int ab;
	int Max;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<a[0];
	}
	for(int i=0;i<n;i++){
		for(int j=i;i<n;j++){
			if(a[j]>a[i]){
				swap(a[j],a[i]); 
			}
		}
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;i<n;j++){
				maxx=max((a[i]&a[j]),minn);
				minn=maxx;
			}
		}
		cout<<maxx;
	}else{
		for(int i=0;i<n;i++){
			ab=(a[i+m-1]&a[i+m-2]);
			m--;
			if(m){
				Max=ab&a[i+m-2];
				continue;
			}	
		}
		cout<<Max;
	}
	
	return 0;
}


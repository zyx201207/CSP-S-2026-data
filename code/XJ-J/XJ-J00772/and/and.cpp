#include<bits/stdc++.h>
using namespace std;

int n,m,max_;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(m==1)
			max_=max(max_,a[i]);
		if(m==n){
			if(i==1)
				max_=a[i];
			else
				max_=max_&a[i];
		}
	}
	if(m==2){
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				max_=max(max_,a[i]&a[j]);
	}
	cout<<max_;
	
	return 0;
}
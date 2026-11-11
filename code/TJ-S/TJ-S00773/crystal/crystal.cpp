#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[510000],s=0,l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int b;
	for(int i=1;i<=n;i++){
		b=a[i];
		for(int i=1;i<=n;i++){
			if(a[i]==b){
				s++;
			}else if(b-a[i]<=m&&a[i]<=b){
				m=m-(b-a[i]);
				s++;
			}
		}
		if(s>l){
			l=s;
		}
	}
	cout<<l;
	return 0;
}

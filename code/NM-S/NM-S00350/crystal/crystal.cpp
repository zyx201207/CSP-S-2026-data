#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int b,c;
	cin>>b>>c;
	for(int i=1;i<=b;i++) cin>>a[i];
	sort(a+1,a+b+1);
	for(int j=1;j<=b;j++){
		s[j]=(j-1)*a[j]-(j-1)*a[j-1]+s[j-1];
			if(s[j]>=c){
				if(s[j]>c) j--;	
				if(a[j]!=a[j+1]){
					cout<<j;
					return 0;	
				} 
			}
	}
	cout<<b;
	return 0;
} 

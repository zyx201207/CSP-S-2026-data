#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,n[10000],l[10000],d;
	cin>>a>>d;
	for(int i=1;i<=a;i++){
		cin>>n[i];
		l[n[i]]++;
	}
	for(int j=1;j<=a;j++){
		if(l[j]>=2) cout<<j;
	}
	return 0;
}

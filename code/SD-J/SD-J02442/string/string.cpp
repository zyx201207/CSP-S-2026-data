#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100001],n,ans,bns;
char c[100001];
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++){
			l+=c[i];
		}
	}
	for(int i=0;i<ans/2;i++){
		if(l[i]!=l[ans-i-1]){
			bns++;
		}
	}
	cout<<bns;
	return 0;
} 

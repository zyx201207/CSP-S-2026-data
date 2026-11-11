#include<bits/stdc++.h>
using namespace std;


long long a[100000005];
char c[100000005];
int n=0;	
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
    }
	int i=1,j=n;
	long long ans=0;
	
	while(j>i){
		a[i]--;
		a[j]--;
		if(c[i]!=c[j]) ans++;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<ans;
	
	
	return 0;
}


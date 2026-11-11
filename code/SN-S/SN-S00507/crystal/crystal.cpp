//刘立恒 SN-S00507 交大附中 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,a[10000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]>m){
		cout<<a[n]-m+m;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}


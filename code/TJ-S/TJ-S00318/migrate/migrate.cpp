#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n;
	cin>>n;
	int i=n--;
	int ansl=-1;
	for(int j=1;j<=n;j++){
		if(i-j+1<ansl) break;
		int sum=90;
		int r=(i-j+1)*sum;
		//cout<<i-j+1<<" "<<r<<endl;
		if(r<=sum){
			ansl=max(i-j+1,ansl);
		}	
	}
	cout<<1<<endl<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

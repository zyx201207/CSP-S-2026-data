#include <iostream>
using namespace std;
int a[10001],sum=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int z=m+1;
	while(z<=n+m){
		for(int i=1;i<=m;i++){
			a[i]--;
			if(a[i]==0){
				a[i]=a[z];
				z++;
			}
		}
		sum++;
	}
	fclose(stdin);
	fclose(stdout);
	cout<<sum;
	return 0;
}

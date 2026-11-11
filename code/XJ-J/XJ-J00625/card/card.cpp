#include<std>
usting <std>
int mian{
	long long int n,m,a[100001];
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>a[i];
	}
	for(int i=1,l=2; i<=n;) {
		while(i!=l) {
			if(a[i]==a[l]) {
				b[l]=a[l];
			} else {

				break;
			}
		}
		i=1;
	}
	return 0;
}
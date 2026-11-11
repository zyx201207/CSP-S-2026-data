#include <iostream>
using namespace std;
int n,m;
int a[200001];
int sum,ans;
struct tmd{
	int s;
	int w;
};
tmd p[200001];
int x;
int q;
int out[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (p[x-1].s!=a[i]){
			p[x].s=a[i];
			p[x].w=i;
			x++;
		}
	}
	for (int i=1;i<=n;i++){
		sum=0;
		if (i==p[q].w){
			q++;
		}
		sum=x-q+1;
		if (sum<=m){
			out[sum]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<out[i]<<' ';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
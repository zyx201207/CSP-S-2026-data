#include<iosteam>
using namespace std;


int main(){
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	int n,m,a[1000],x[1000],y[1000],z[1000],maxn = 0,maxn1 = 0;b = 1;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)(
		cin >> a[i];
	)
	while(n == 0){
		int c = 1;
		for(int i = 1;;i++){
			if(a[c+1]==0)
				a[c+1] == a[1];
			x[i] = a[c]%(2*i);
			y[i] = a[c+1]%(2*i);
			if(x[i] == y[i]){
				z[i] = 1;
			}
			if(a[c] == 0&&a[c+1] == 0)
				break;
		}
		maxn1 = maxn;
		for(int i = 100;;i--){
			maxn += z[b]*(2*b);
			b++;
		}
		if(maxn <= maxn1){
			maxn = maxn1;
			maxn1 = 0;
		}
		c++;
		n--;
	}
	cout << maxn;
	return 0;
}
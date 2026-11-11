#include <bits/stdc++.h>
using namespace std;
long long a[200005],n;
long long sum=0,sum2=0,sum3=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	//for(int i=1;i<=n;i++){
	//	cout << a[i] << " " << c[i] << "\n";
	//}
	if(sum&1){
		int x=(sum+1)/2,y=0;
		for(int i=1;i<=n;i++){
			sum2+=a[i];
			if(sum2>=x){
				y=i;
				break;
			}
		}
		a[y]=a[y]-sum2+x-1;
		for(int i=n;i>y;i--){
			a[i+1]=a[i];
			c[i+1]=c[i];
		}
		a[y+1]=sum2-x;
		c[y+1]=c[y];
		n++;
	}
	cout << n << endl;
	for(int i=1;i<=n;i++){
		cout << a[i] << " " << c[i] << "\n";
	}
	long long l=1,r=n,ll=a[1],rr=a[n];
	while(l<r){
		cout << (ll>=rr) << "\n";
		if(ll>=rr){
			cout << "r--!!! ll=" << ll << ",rr=" << rr << endl;
			if(c[l]!=c[r])sum3+=rr;
			r--;
			ll=ll-rr;
			if(r>l)rr=a[r];
			else rr=0;
			//cout << "r--!!! ll=" << ll << ",rr=" << rr << endl;
		}
		else{
			cout << "l++!!! ll=" << ll << ",rr=" << rr << endl;
			if(c[l]!=c[r])sum3+=ll;
			l++;
			rr=rr-ll;
			if(r>l)ll=a[l];
			else ll=0;
		}
	}
	sum3=sum3+(ll+rr)/2;
	cout << sum3;
	return 0;
}

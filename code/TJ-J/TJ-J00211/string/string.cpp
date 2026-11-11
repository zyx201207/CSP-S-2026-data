#include <bits/stdc++.h>
using namespace std;
long long a[200005]={0};
struct duan{
	int p;
	char q;
};
duan b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> b[i].p >> b[i].q;
		a[i]=b[i].p+a[i-1];
	}
	char x=b[0].q,y=b[n-1].q;
	long long s=0;
	if(a[n-1]%2==0){
		for(long long i=0;i<(a[n-1])/2;i++){
			if(x!=y)s++;
			if(i+1==a[i]){
				x=b[i+1].q;
			}	
			if(a[n-1]-i-1==a[n-1-i-1]){
				y=b[n-i-1].q;
			}
		}
	}
	else{
		for(long long i=0;i<(a[n-1]+1)/2-1;i++){
			if(x!=y)s++;
			if(i+1==a[i]){
				x=b[i+1].q;
			}	
			if(a[n-1]-i-1==a[n-1-i-1]){
				y=b[n-i-1].q;
			}
		}
	}
	cout << s;
	return 0;
}

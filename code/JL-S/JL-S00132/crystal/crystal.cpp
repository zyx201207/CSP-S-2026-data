#include<bits/stdc++.h>

using namespace std;
const long MAXN = 5*10e5+5;
long long n,m;
long long a[MAXN] = {0};
bool check1(long x){
	
	for (long i=x;i<=n;i++){
		int temp=0;
		for (long j=i-x+1;j<i;j++){
			
			temp += a[i] - a[j];
//			cout << temp << '?' << endl;
			}
//		cout << temp << '!' << endl;
		if (temp<=m) {
//			cout << x << "**" << i << endl;
			return true;
			}
		}
		
//	cout << "no" << endl;
	return false;
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		}
	sort(a+1,a+1+n);
	int l=1,r=n;
	int mid;
	int pian=0;
	while (r!=l){			//
		mid = l+(r-l)/2;
		if (check1(mid)) {
			l=mid+1;
			pian=0;
			}else{
				r=mid;
				pian=1;
				}
 		
		}
	
	cout << mid-pian;
	
	
//	for (int i=1;i<=n;i++){
//		cout << a[i];
//		}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

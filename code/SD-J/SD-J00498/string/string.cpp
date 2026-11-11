#include<bits/stdc++.h>
using namespace std;
long long n,sum;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	long long i = 1,j = n;
	while(i < j){
		//cout << sum << ' ' << i << ' ' << j << endl;
		if(a[i] > a[j]){
			long long cnt = a[j];
			if(b[i] != b[j]){
				sum += cnt;
			}
			j--;
			a[i] -= cnt;
		}
		else if(a[i] == a[j]){
			long long cnt = a[j];
			if(b[i] != b[j]){
				sum += cnt;
			}
			j--;
			i++;
		}
		else{
			long long cnt = a[i];
			if(b[i] != b[j]){
				sum += cnt;
			}
			i++;
			a[j] -= cnt;
		}
		
	}
	cout << sum;
	return 0;
}

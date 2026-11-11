#include <bits/stdc++.h>
using namespace std;
long long a[2000005],b[20000006];
char c[2000005],d[20000065];
bool ou = false;
long long sum,sum1,ind,q,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	bool flag = true;
	for(int i = 2; i<=n; i++){
		if(c[i] != c[i-1]) {
			flag = false;
			break;
		}
	}
	if(flag){
		cout << 0;
		return 0;
	}
	if(sum%2 == 0) {
		ou = true;
		sum/=2;
	}
	else (sum/=2)+=1;
	for(int i = 1; i<=n; i++){
		if(sum1+a[i] > sum && sum1 <= sum){
			q = sum1+a[i]-sum;
			ind = i;
			break;
		}
		sum1+=a[i];
	}
	for(int i = 1; i<=n+1; i++){
		if(i == ind){
			b[i] = a[i]-q;
			d[i] = c[i];
			b[i+1] = q;
			d[i+1] = c[i];
			i++;
			continue;
		}
		if(i>ind){
		b[i] = a[i-1];
		d[i] = c[i-1];
		}
		else{
			b[i] = a[i];
			d[i] = c[i];
		}
	}
	//for(int i = 1;i<= n+1; i++) cout << b[i] << d[i] << endl;
	//cout << ind;  
	
	
	if(!(ou)){
		long long i = ind-1, j=ind+1;
		while(i>=1 && j<=n){
			if(b[i] == b[j] && d[i] == d[j]){
				i--;
				j++;
			}
			else if(b[i] != b[j] && d[i] == d[j]){
				cnt+=abs(b[i]-b[j]);
				if(b[i] > b[j]) b[j+1] -= abs(b[i]-b[j]);
				else b[i-1] -= abs(b[i]-b[j]);
				i--;
				j++;
			}
			else{
				cnt+=max(b[i],b[j]);
				i--;
				j++;
			}
		}
	}
	else{
		long long i = ind-1, j=ind+1;
		cout << i << " " << j;
		while(i>=1 && j<=n+1){
			if(b[i] == b[j] && d[i] == d[j]){
				i--;
				j++;
			}
			else if(b[i] != b[j] && d[i] == d[j]){
				cnt+=abs(b[i]-b[j]);
				if(b[i] > b[j]) b[j+1] -= abs(b[i]-b[j]);
				else b[i-1] -= abs(b[i]-b[j]);
				i--;
				j++;
			}
			else{
				cnt+=max(b[i],b[j]);
				cout << cnt << endl;
				i--;
				j++;
			}
		}
	}
	cout << cnt;
	return 0;
} 

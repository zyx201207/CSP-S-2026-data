#include <bits/stdc++.h>
using namespace std;

struct p{
	int a, sum;
	char b;
	
};
p l, r;
int n;
long long a[100010] , d[100010], sum, cnt, leave;
char b[100010], whi;
string s;
int main(){
	freopen("travel.in" , "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i]; 
		sum += a[i];
		d[i] = d[i-1] + a[i];
		}
	l.a = 1;
	l.b = b[1];
	l.sum = a[1];
	r.a = n;
	r.b = b[n];
	r.sum = a[n];
	while(l.a!=r.a){
		if(l.b!=r.b){
			if(l.sum > r.sum){
				cnt +=l.sum-r.sum;
				l.sum = l.sum-r.sum;
				l .a++;
				l.sum = a[l.a];
				l.b = b[l.a];
			}
			else if(l.sum < r.sum){
				cnt += r.sum-l.sum;
				r.sum = r.sum-l.sum;
				l .a++;
				l.sum = a[l.a];
				l.b = b[l.a];
			}
			else
			{
				l.a++;
				r.a--;
				l .a++;
				l.sum = a[l.a];
				l.b = b[l.a];
				l.sum = a[l.a];
				l.b = b[l.a];
			}
			
			}
		else if (l.b==r.b) {
			if(l.sum > r.sum) {
				l.sum -= r.sum;
				r.a--;
				r.sum = a[r.a];
				r.b = b[r.a];	}
			else if(l.sum < r.sum) {
				r.sum -= l.sum;
				l.a++;
				l.sum = a[l.a];
				l.b = b[l.a];	}	}
 			
			 
			
		}
	
		cout << cnt;
	return 0;
}

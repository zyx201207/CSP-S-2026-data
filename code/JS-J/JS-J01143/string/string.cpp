#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> s[i];
	}
	int h = 1,t = n;
	while(h < t){
		if(s[h] != s[t]){
			if(a[h] > a[t]){
				cnt += a[t];
				a[h] -= a[t];
				t --;
			}
			else if(a[h] == a[t]){
				cnt += a[h];
				h++,t--;
			}
			else{
				cnt += a[h];
				a[t] -= a[h];
				h ++;
				
			}
		}
		else{
			if(a[h] > a[t]){
				a[h] -= a[t];
				t --;
			}
			else if(a[h] == a[t]){
				h++,t--;
			}
			else{
				a[t] -= a[h];
				h ++;
			}
		}
	}
	cout << cnt;
	return 0;
}

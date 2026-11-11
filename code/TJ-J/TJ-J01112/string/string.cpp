#include<bits/stdc++.h>
using namespace std;
int n;
int cs[200005];
char sz[200005];
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int y = 0;
	bool t;
	for(int i = 1;i <= n;i++){
		cin >> cs[i];
		cin >> sz[i];
		int w = cs[i];
		int l = 1;
		if(!t){
			l+=cs[i];
		}
		for(int j = l;j<=w;j++){
			a[j] = sz[i];
			y++;
			if(j==cs[i]){
				t=false;
			}
		}
	}
	bool h;
	for(int i = 1;i <= y;i++){
		if(a[i]==a[i-1]&&a[i]==a[i+1]){
			h=true;
		}
		if(i==y){
			if(h){
				cout << 0;
				return 0;
			}
		}
	}
	if(y%2==1){
		int cnt = 0;
		int t = y/2;
		int p = t+2;
		int q = t;
		for(int i = 1;i <= q;i++){
			if(a[t]==a[p]){
				t-=1;
				p+=1;
				break;
			}
			else{
				cnt++;
				t-=1;
				p+=1;
			}
		}
		cout << cnt;
		return 0;
	}
	if(y%2==0){
		int sum = 0;
		int u = y/2;
		int k = y/2+1;
		int q = u;
		for(int i = 1;i <= q;i++){
			if(a[u]==a[k]){
				break;
			}
			else{
				sum++;
				u-=1;
				k+=1;
			}
		}
		cout << sum;
		return 0;
	}
	return 0;
} 

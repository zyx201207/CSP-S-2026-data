#include <bits/stdc++.h>
using namespace std;
string a;
long long n,ans;
struct node{
	long long x;
	char y;
}w[200005];
void nb(long long l,long long r){
	while(l<r){
		if(w[l].y != w[r].y){
			if(w[l].x<w[r].x){
				ans+=w[l].x;
				w[r].x-=w[l].x;
				l++;
			}
			else if(w[l].x>w[r].x){
				ans+=w[r].x;
				w[l].x-=w[r].x;
				r--;
			}
			else{
				ans+=w[r].x;
				l++;
				r--;
			}
		}
		else if(w[l].x != w[r].x){
			if(w[l].x<w[r].x){
				w[r].x -= w[l].x;
				l++;
			}
			else if(w[l].x>w[r].x){
				w[l].x-=w[r].x;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			l++;
			r--;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> w[i].x >> w[i].y;
	}
	nb(1,n);
	cout << ans;
	return 0;
}

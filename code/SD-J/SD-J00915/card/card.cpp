#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],t[500010];
long long st[500010],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int tim=1;tim<=n;tim++){
		for(int i=tim;i<=n;i++){
			for(int j=1;j<=top;j++){
				if(st[j]==a[i]){
					top=j-1;
					break;
				}
			}
			st[++top]=a[i];
		}
		while(top!=0){
			t[st[top]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++){
		cout << t[i] << ' ';
	}
	return 0;
}

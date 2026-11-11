#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int x,y;
	for(int i=1;i<=n;i++){
		if(m==1){
			cout << n;
			break;
		}else if(m==2){
			if(a[n]==1&&a[1]==1)x++;
			if(a[1]==2&&a[n]==2)y++;
			if(a[1]==1&&a[n]==2)y++;
			if(a[1]==2&&a[n==1])x++;
		}
	}
	cout << x << " " << y;
	return 0;
} 

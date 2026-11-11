#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==a[7]){
		cout<<n;
		return 0;
	}
	int y=2;
	for(int i=1;i<=m;i++){
		sort(a+1,a+n+1);
		a[1]++;
		if(a[1]==a[y]){
			y++;
			if(m-i<y){
				break;
			}
		}

	}	
	cout<<y;
	return 0;
} 

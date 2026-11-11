#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int arr[1000002][1000002];
	int n,min;
	cin>>n;
	for(int a=0;a<n;a++){
		int tmp;
		for(int c=0;c<2;c++){
			cin>>arr[a][c];
			tmp+=a;
		}
		min=tmp/2;
	}
	
	return 0;
}

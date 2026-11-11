#include<bits/stdc++.h>
using namespace std;
int n,a[1000000];
int d;
string c,e;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int s=0,begin=1,end=n;
	while(n--){

		if(n%2!=0&&a[begin]==a[end]){
			if(a[begin]==a[end]&&c[begin]==c[end]){
				begin++;
				end--;			}
		}else{
			c[begin]==a[end];
			s+=a[begin];
		}

	}
	cout<<s-2;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n =0;
	char ans[100000] = {};
	char a[100000] = {};char b[100000] = {};
	cin>>n;
	for(int i = 0;i<n;i++){
		int cnt = 0;char pi = ' ';
		cin>>cnt>>pi;
		int rng = 0;
		while(1){
			if((ans[rng]>='a'&&ans[rng]<='z')!=1){
				break;
			}
			rng++;
		}
		while(cnt>0){
			ans[rng] = pi;
			cnt--;
			rng++;
		}
		
	}
	int size = 0;
	while(1){
		if((ans[size]>='a'&&ans[size]<='z')!=1){
				break;
			}
			size++;
		
	}
	for(int i = 0;i<size;i++){
		a[i]=ans[i];
		cout<<a[i];
	}
	int d = 0;
	cout<<endl;
	for(int i = size-1;i>=0;i--){
		
		b[d]=ans[i];
		d++;
	}
	int sum =0;
	for(int i = 0;i<size;i++){
		if(a[i]!=b[i]){
			sum++;		
		}
		
	}
	cout<<sum;
	
	return 0;
}
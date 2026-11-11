#include<bits/stdc++.h>
using namespace std;
int n,m;
bool t=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			t = false;
		}
	}
	if(t==true){
		for(int i=0;i<n;i++){
			cout << n << " ";
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	t = true;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			t = false;
		}
	}
	if(t = true){
		for(int i=0;i<n;i++){
			cout << i+1 << " ";
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

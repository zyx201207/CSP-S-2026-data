#include<bits/stdc++.h>
using namespace std;
bool t=true;
int n,m,cnt,j=0;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n/2;i++){
		if(a[i]==a[i+1]){
			cnt++;
		}
		else if(m>a[n/2]-abs(a[i])){
			a[i] = a[n/2];
			m -= abs(a[n/2])-abs(a[i]);
			cnt++;
		}
		else{
			break;
		}
	}
	for(int i=n/2;i<n-1;i++){
		j=i;
		if(a[i] != a[i+1]){
			break;
		}
		else{
			cnt++;
		}
	}
	while(true){
		if(m>(a[j+1]-a[j])*j){
			cnt++;
			m -= (a[j+1]-a[j])*j;
		}
		else{
			break;
		}
		j++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,a[200005],cnt = 0,count = 0;
	cin>>n;
	string c[200005]; 
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cin>>c[i];
		count += a[i]; 
	}
	for(int j = 1;j <=count/2+1;j++){
		if(c[j] == c[count-j]){
			if(a[j] == a[count-j]){
				continue;
			}
			else{
				cnt += a[count-j+1]-a[j];
			}
			cnt += a[j];
		}
	}
	cout<<cnt;
		return 0;
} 

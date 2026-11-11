#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[123456];
	int b[123456];
	int c[123456];
	long long n,m;
	cin >> n;
	for(int i = 1;i < n;i++){
		cin >> a[i];
		b[i] = 0;
	}
	for(int i = 1;i < n;i++){
		for(int j = i;j < n;j++){
			if(b[j] == 1){
				for(int k = i;k < j;k++){
					b[k] = 0;
				}
			}
			else{
				b[j] = 1;
			}
		}
		for(int j = i;j < n;j++){
			if(b[j] == 1){
				c[j]++;
				b[j] = 0;
			}
		}
	}
	for(int i = 1;i < n;i++){
		cout << c[i] << " ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
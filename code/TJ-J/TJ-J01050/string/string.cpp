#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[105];
	char b,c[105];
	cin >> n;
	int num = 0;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b;
		num = num+a[i];
		for(int j=num-a[i];j<num;j++){
			c[j]=b;
		}
	}
	if(n==1){
		cout << "0";
		return 0;
	}
	if(c[0]==c[n-1]&&(n==2||n==3)){
		cout << "0";
		return 0;
	}
	int sum=0;
	for(int i=0;i<(num/2);i++){
		if(c[i]!=c[n-i-1]){
			sum++;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

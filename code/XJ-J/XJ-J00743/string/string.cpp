#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char s;
};
long long n,sum;
node a[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n; i++){
		cin >> a[i].num >> a[i].s;
	}
	int i = 1,j = n;
	while (i < j){
		if (a[i].s != a[j].s){
			if (a[i].num > a[j].num){
				sum += a[j].num;
				a[i].num -= a[j].num;
				j--;
			}
			else if (a[i].num == a[j].num){
				sum += a[i].num;
				a[j].num = 0;
				a[i].num = 0;
				i++;		
				j--;	
			}
			else{
				sum += a[i].num;
				a[j].num -= a[i].num;
				i++;		
			}
		}
		else{
			if (a[i].num >= a[j].num){
				a[i].num -= a[j].num;
				j--;
			}
			else if (a[i].num == a[j].num){
				a[i].num = 0;
				a[j].num = 0;
				i++;
			}
			else{
				a[j].num -= a[i].num;
				i++;		
			}			
		}
	}
	cout << sum;
} 

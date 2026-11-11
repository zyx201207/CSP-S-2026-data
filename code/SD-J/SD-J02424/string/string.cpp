#include<bits/stdc++.h>
using namespace std;
struct no{
	long long q;
	char s;
}a[200005];
int n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].s;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].s==a[j].s){
			if(a[i].q>a[j].q){
				a[i].q=a[i].q-a[j].q;
				j--;
			}
			else if(a[i].q<a[j].q){
				a[j].q=a[j].q-a[i].q;
				i++;
			}
			else{
				i++;
				j--;
			}
		}
		else{
			if(a[i].q>a[j].q){
				sum+=a[j].q;
				a[i].q=a[i].q-a[j].q;
				j--;
			}
			else if(a[i].q<a[j].q){
				sum+=a[i].q;
				a[j].q=a[j].q-a[i].q;
				i++;
			}
			else{
				sum+=a[i].q;
				i++;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
3
2 a
2 b
1 c
_______________________________
2
2 a
3 a

_______________________________
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
________________________________
3
2 a
2 b
1 c

*/

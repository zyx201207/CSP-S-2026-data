#include <bits/stdc++.h>
using namespace std;
struct N{char s;long long num;}a[100100],b[100100];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].num>>a[i].s;
		b[n-i+1].num=a[i].num;
		b[n-i+1].s=a[i].s;
	}
	long long i=1,j=1,s=0;
	while(i<=n&&j<=n){
		 
		if(a[i].s!=b[j].s){
			if(a[i].num>b[j].num){
				a[i].num=a[i].num-b[j].num;s+=b[j].num;
				j++;
			}
			else if(a[i].num<b[j].num){
				b[j].num=b[j].num-a[i].num;s+=a[i].num;
				i++;
			}
			else if(a[i].num==b[j].num){
				s+=a[i].num;j++;i++;
			}
		}
		else if(a[i].s==b[j].s){
			if(a[i].num>b[j].num){
				a[i].num=a[i].num-b[j].num;
				j++;
			}
			else if(a[i].num<b[j].num){
				b[j].num=b[j].num-a[i].num;
				i++;
			}
			else if(a[i].num==b[j].num){
				j++;i++;
			}
		}
	}
	cout << s/2;
	return 0;
}

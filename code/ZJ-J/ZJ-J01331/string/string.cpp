#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct node{
	long long x;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				j--;
			}
			else if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				i++;
			}
			else{
				i++,j--;
			}
		}
		else{
			if(a[i].x>a[j].x){
				a[i].x-=a[j].x;
				sum+=a[j].x;
				j--;
			}
			else if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				sum+=a[i].x;
				i++;
			}
			else{
				sum+=a[i].x;
				i++,j--;
			}
		}
	}
	cout<<sum;
	return 0;
}


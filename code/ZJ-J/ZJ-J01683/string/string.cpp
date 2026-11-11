#include<bits/stdc++.h>
using namespace std;
int n,r,l;
long long sum;
struct str{
	long long num;
	char c;
};
str a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%ld %c",&a[i].num,&a[i].c);
	}
	r=n;
	l=1;
	while(r>l){
		if(a[l].c!=a[r].c){
			if(a[l].num<a[r].num){
				sum=sum+a[l].num;
				a[r].num=a[r].num-a[l].num;
				l++;
			}
			else if(a[l].num>a[r].num){
				sum=sum+a[r].num;
				a[l].num=a[l].num-a[r].num;
				r--;
			}
			else{
				sum=sum+a[r].num;
				r--;
				l++;
			}
		}
		else{
			if(a[l].num<a[r].num){
				a[r].num=a[r].num-a[l].num;
				l++;
			}
			else if(a[l].num>a[r].num){
				a[l].num=a[l].num-a[r].num;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}

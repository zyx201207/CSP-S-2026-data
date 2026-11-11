#include<bits/stdc++.h>
using namespace std;
struct A{
	long long num1;
	char word;
	long long num2;
}; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	A a[n+10];
	long long reat=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num1;
		cin>>a[i].word;
		a[i].num2=a[i-1].num2+a[i].num1;
		reat+=a[i].num1;
	}
	int c=0;
	int f=0;
	int b=0;
	for(int i=1;i<=n;i++){
		if(a[i].num2<reat/2) continue;
		else if(a[i].num2==reat/2){
			f=1;
			break;
		}
		else {
			f=2;
			b=i;
			break;
		}
	}
	int d=n;
	int m;
	int z;
	if(f==2){
		int x=a[b].num2-reat/2;
		int y=reat/2-a[b-1].num2;
		if(x>y){
			a[b].num1-=2*y;
			m=reat/2-y;
			z=reat/2+y;
		}
		else if(x<y){
			a[b].num1-=2*x;
			m=reat/2-x;
			z=reat/2+x;
		}
		else{
			a[b].num1=0;
			m=reat/2-x;
			z=reat/2+x;
		}
	}
	else if(f==1){
		m=reat/2;
		z=m;
	}
		int i=1;
		while(a[i+1].num2<m&&a[d-1].num2>z){
			if(a[i].word!=a[d].word){
				if(a[i].num1<a[d].num1&&a[i].num1>=0&&a[d].num1>=0){
					c+=a[d].num1-a[i].num1;
					i++;
					a[d].num1-=c;
				}
				else if(a[i].num1>a[d].num1&&a[i].num1>=0&&a[d].num1>=0){
					c+=a[i].num1-a[d].num1;
					d--;
					a[i].num1-=c; 
				}
				else{
					c+=a[i].num1;
					i++;
					d--;
				}
			}
			else {
				if(a[i].num1<a[d].num1&&a[i].num1>=0&&a[d].num1>=0){
					i++;
					a[d].num1-=a[d].num1-a[i].num1;
				}
				else if(a[i].num1>a[d].num1&&a[i].num1>=0&&a[d].num1>=0){
					d--;
					a[i].num1-=a[i].num1-a[d].num1; 
				}
				else{
					i++;
					d--;
				}
			}
		}
		cout<<c;
	return 0;
}

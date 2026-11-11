#include<bits/stdc++.h>
using namespace std;
struct sb{
	int s;
	string c;
}a[7114514];
int main(){
	int n;
	long long o=0,sum=0;
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		o+=a[i].s;
	}
	o/=2;
	long long p=0,q=0;
	int x=0,y=0,i=1,j=n;
	for(;;){
		if(p==o&&x==0){
			break;
		}
		if(x==0){
			if(p+a[i].s>=o){
				x=o-p;
				p=o;
			}else{
				x=a[i].s;
				p+=x;
			}
		}
		if(y==0){
			if(q+a[j].s>=o){
				y=o-q;
				q=o;
			}else{
				y=a[j].s;
				q+=y;
			}
		}
		if(x>=y){
			if(a[i].c==a[j].c){	
			}else{
				sum+=y;
				
			}
			x-=y;
			y=0;
			j--;
			if(x==0){
				i++;
			}
		}else{
			if(a[i].c==a[j].c){	
			}else{
				sum+=x;
			}
			y-=x;
			x=0;
			i++;
		}
	}
	cout<<sum;
	return 0;
}

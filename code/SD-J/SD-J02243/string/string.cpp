#include<bits/stdc++.h>
using namespace std;
int n,k,b;
long long c;
struct ff{
	int num;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].num);
		cin>>a[i].s;
	}
	for(long long i=0,j=n-1;i<=j;){\
		if(b==1){
			a[i].num-=k;
		}
		else if(b==2){
			a[j].num-=k;
		}
		if(a[i].num==a[j].num){
			if(a[i].s!=a[j].s){
				c+=a[i].num;
				i++;
				j--;
				b=0;
			}
			else{
				i++;
				j--;
				b=0;
			}
		}
		else{
			k=min(a[i].num,a[j].num);
			if(a[i].s!=a[j].s){
				c+=min(a[i].num,a[j].num);	
				if(a[i].num>a[j].num){
					j--;
					b=1;
				}
				else{
					i++;
					b=2;
				}
			}
			else{
				if(a[i].num>a[j].num){
					j--;
					b=1;
				}
				else{
					i++;
					b=2;
				}
			}
		}
	}
	printf("%lld",c);
	return 0;
}


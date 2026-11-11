#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long l;
	char aa;
}a[200005];
long long n,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].l>>a[i].aa;
	}
	for(int i=0,j=n-1;i<=j;){
		if(a[i].aa==a[j].aa){
			if(a[i].l==a[j].l){
				i++,j--;
			}else{
				if(a[i].l>a[j].l){
					a[i].l-=a[j].l;
					j--;
				}else{
					a[j].l-=a[i].l;
					i++;
				}
			}
		}else{
			if(a[i].l==a[j].l){
				h+=a[i].l;
				i++,j--;
			}else{
				if(a[i].l>a[j].l){
					h+=a[j].l;
					a[i].l-=a[j].l;
					j--;
				}else{
					h+=a[i].l;
					a[j].l-=a[i].l;
					i++;
				}
			}
		}
	}
	cout<<h;
	return 0;
}

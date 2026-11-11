#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+10;
struct sa{
	long long a;
	char b;
}z[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long q;
	cin>>q;
	for(int i=1;i<=q;i++) cin>>z[i].a>>z[i].b;
	long long l=1,r=q;
	long long sum=0;
	long long h=0,k=0;
	while(l<r){
		if(z[l].b!=z[r].b){
			if(z[l].a-h==z[r].a-k){
				sum+=z[l].a-h;
				l++;
				r--;
				h=0;
				k=0;
			}else{
				if(z[l].a-h>z[r].a-k){
					sum+=z[r].a-k;
					h+=z[r].a-k;
					k=0;
					r--;
				}else{
					sum+=z[l].a-h;
					k+=z[l].a-h;
					h=0;
					l++;
				}
			}         
		}else{
			if(z[l].a-h==z[r].a-k){
				l++;
				r--;
				h=0;
				k=0;
			}else{
				if(z[l].a-h>z[r].a-k){
					h+=z[r].a-k;
					k=0;
					r--;
				}else{
					k+=z[l].a-h;
					h=0;
					l++;
				}
			}
		}
	}cout<<sum;
	return 0;
}         
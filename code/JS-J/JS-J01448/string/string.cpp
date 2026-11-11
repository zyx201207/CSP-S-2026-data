#include<bits/stdc++.h>
using namespace std;
struct jc{
	long long num;
	char c;
}a[300000];
long long n,m,ans;
long long h,l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>> n;
    for(long long i=1;i<=n;i++){
		cin>> a[i].num >> a[i].c;
		h+=a[i].num;
	}
	h/=2;
	l=1;
	r=n;
	while(h>0){
		if(a[l].c!=a[r].c){
			if(a[l].num>a[r].num){
				ans+=min(h,a[r].num);
				a[l].num-=a[r].num;
				h-=min(h,a[r].num);
				r--;
			}
			else if(a[l].num==a[r].num){
				ans+=min(h,a[l].num);
				h-=min(h,a[l].num);
				l++;
				r--;
			}
			else{
				ans+=min(h,a[l].num);
				a[r].num-=a[l].num;
				h-=min(a[l].num,h);
				l++;
			}
		}
		else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				h-=min(h,a[r].num);
				r--;
			}
			else if(a[l].num==a[r].num){
				h-=min(h,a[l].num);
				l++;
				r--;
			}
			else{
				a[r].num-=a[l].num;
				h-=min(a[l].num,h);
				l++;
			}
		}
			
    }
    cout<< ans <<endl;
    return 0;
}

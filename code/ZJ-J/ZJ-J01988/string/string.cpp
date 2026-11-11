#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
struct jj{
	long long g;
	char z; 
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i].g,&a[i].z);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].z==a[r].z){
			if(a[l].g>a[r].g){
				a[l].g-=a[r].g;
				r--;
			}else if(a[l].g<a[r].g){
				a[r].g-=a[l].g;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			sum+=min(a[l].g,a[r].g);
			if(a[l].g>a[r].g){
				a[l].g-=a[r].g;
				r--;
			}else if(a[l].g<a[r].g){
				a[r].g-=a[l].g;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	
	return 0;
} 

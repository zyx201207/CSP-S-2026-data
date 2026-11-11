#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
struct node{
	long long w;
	char x;
}a[N];
long long n,cnt=1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[cnt].w>>a[cnt].x;
		if(cnt!=1&&a[cnt].x==a[cnt-1].x){
			a[cnt-1].w+=a[cnt].w;
		}else{
			cnt++;
		}
	}
	n=cnt-1;
	if(n==1){
		cout<<0;
		return 0;
	}
	long long i=2,j=n-1,i_s=a[1].w,j_s=a[n].w,i_c=a[1].x,j_c=a[n].x;
	if(i_c!=j_c){
		ans+=min(i_s,j_s);
	}
	while(i<=j){
		if(i_s<j_s){
			i_s+=a[i].w;
			i_c=a[i].x;
			if(i_s<j_s){
				if(i_c!=j_c){
					ans+=a[i].w;
				}
			}else{
				if(i_c!=j_c){
					ans+=a[i].w-i_s+j_s;
				}
			}
			i++;
		}else{
			j_s+=a[j].w;
			j_c=a[j].x;
			if(j_s<i_s){
				if(j_c!=i_c){
					ans+=a[j].w;
				}
			}else{
				if(j_c!=i_c){
					ans+=a[j].w-j_s+i_s;
				}
			}
			j--;
		}
	}
	cout<<ans;
	return 0;
}

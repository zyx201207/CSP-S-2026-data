#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	char c;
	long long l;
	long long r;
}arr[N];
node brr[2*N];
long long zuo[N];
long long yo[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	long long len=0;
	for(int i=1;i<=n;i++){
		int ge;
		cin>>ge>>arr[i].c;
		arr[i].l=len+1;
		arr[i].r=len+ge;
		zuo[i]=arr[i].l;
		yo[i]=arr[i].r;
		len+=ge;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long dl=arr[i].l;
		long long dr=arr[i].r;
		long long fl=len-dr+1;
		long long fr=len-dl+1;
		long long flwei=lower_bound(yo+1,yo+1+n,fl)-yo;
		long long frwei=lower_bound(yo+1,yo+1+n,fr)-yo;
		if(flwei==frwei&&arr[i].c!=arr[flwei].c){
			ans+=(fr-fl)+1;
			continue;
		}
		for(int j=flwei;j<=frwei;j++){
			if(arr[j].c!=arr[i].c){
				if(j==flwei){
					ans+=(arr[j].r-fl+1);
				}else if(j==frwei){
					ans+=(fr-arr[j].l+1);
				}else{
					ans+=(arr[j].r-arr[j].l+1);
				}
			}
			
		}
	}
	cout<<ans/2;
	return 0;
}

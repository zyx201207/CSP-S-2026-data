#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll n,a[MAXN],ans,mid;
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	mid=(mid+1)/2;
	ll l=1,r=n,suml=a[1],sumr=a[n],num=0;
	while(1){
		//cout<<"l: "<<l<<" r: "<<r<<" suml: "<<suml<<" sumr: "<<sumr<<" num: "<<num<<"\n";
		if(suml==sumr){
			if(num+sumr>mid){
				break;
			}
			else{
				num+=sumr;
			}
			if(c[l]!=c[r]){
				ans+=sumr;
			}
			l++;
			r--;
			suml=a[l];
			sumr=a[r];
		}
		else if(suml>sumr){
			if(num+sumr>mid){
				break;
			}
			else{
				num+=sumr;
			}
			if(c[l]!=c[r]){
				ans+=sumr;
			}
			suml-=sumr;
			r--;
			sumr=a[r];
		}
		else{
			if(num+suml>mid){
				break;
			}
			else{
				num+=suml;
			}
			if(c[l]!=c[r]){
				ans+=suml;
			}
			sumr-=suml;
			l++;
			suml=a[l];
		}
	}
	if(num<mid and c[l]!=c[r]){
		ans+=min(suml,sumr);
	}
	cout<<ans;
	return 0;
}
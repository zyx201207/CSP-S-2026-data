#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long ans,len,l[N],r[N],ss;
int n,a[N],mid,s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
	}
	for(int i=1;i<=n;i++){
		if(r[i]>len/2){
			mid=i;
			break;
		}
	}
	s=n,ss=len;
	for(int i=1;i<mid;i++){
		int dcl=a[i];
		while(dcl){
			if(c[i]!=c[s]){
				if(dcl>=ss-l[s]+1){
					dcl-=ss-l[s]+1;
					ans+=ss-l[s]+1;
					s--;
					ss=r[s];
				}
				else{
					ss=ss-dcl;
					ans+=dcl;
					break;
				}
			}
			else{
				if(dcl>=ss-l[s]+1){
					dcl-=ss-l[s]+1;
					s--;
					ss=r[s];
				}
				else{
					ss=ss-dcl;
					break;
				}
			}
		}
	}
	if(l[mid]<=(len+1)/2){
		if((len+1)/2-l[mid]>=r[mid]-(len+1)/2){
			int dcl=(len+1)/2-l[mid]-r[mid]+(len+1)/2,p=mid+1;
			while(dcl){
				if(dcl<=a[p]){
					ans+=dcl;
					break;
				}
				else{
					dcl-=a[p];
					ans+=a[p];
					p++;
				}
			}
		} 
	}
	cout<<ans;
	return 0;
}

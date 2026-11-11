#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n;
int a[N];
char c[N];
void cao(int frt,int bck,int frt_len,int bck_len,ll sum){
	if(bck-frt<=0){
		cout<<sum<<endl;
		return;
	}
	if(c[frt]==c[bck]){
		if(frt_len>bck_len){
			cao(frt,bck-1,frt_len-bck_len,a[bck-1],sum);
		}
		else if(frt_len<bck_len){
			cao(frt+1,bck,a[frt+1],bck_len-frt_len,sum);
		}
		else{
			cao(frt+1,bck-1,a[frt+1],a[bck-1],sum);
		}
	}
	else{
		if(frt_len>bck_len){
			cao(frt,bck-1,frt_len-bck_len,a[bck-1],sum+bck_len);
		}
		else if(frt_len<bck_len){
			cao(frt+1,bck,a[frt+1],bck_len-frt_len,sum+frt_len);
		}
		else{
			cao(frt+1,bck-1,a[frt+1],a[bck-1],sum+frt_len);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	cao(1,n,a[1],a[n],0);
	return 0;
}
